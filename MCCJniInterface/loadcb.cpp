// same old routines as computer boards provide, but with my
// dummy routines to the DLL


#include <windows.h>
#include <stdio.h>

#include "mycb.h"
#include "cbw.h"


HMODULE CBLibrary = 0;

#define DESIREDREVISION 5.0f

bool HaveCBDLL()
{
  return (CBLibrary != 0);
}
bool LoadCBDLL()
{
  // this only works for windows 95, so check windows version !  
  // should now work with windows NT, so remove the windows version stuff !
  /*OSVERSIONINFO OsVersion;
  OsVersion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
  GetVersionEx(&OsVersion);
  if (OsVersion.dwPlatformId != VER_PLATFORM_WIN32_WINDOWS) return false;  */

  CBLibrary = LoadLibrary("cbw32.dll");
  if (CBLibrary == 0) return false;

  // have library - so set poitner so absolutely everything
  // first, though, check it's version 5, or it will explode !!
  myGetRevision = (int(__stdcall*)(float*, float*)) (int(__stdcall*)()) GetProcAddress(CBLibrary, "cbGetRevision");
  float DLLNum, VDXNum;
  (*myGetRevision) (&DLLNum, &VDXNum);
  if (DESIREDREVISION != DLLNum)
  {
    char text[128];
    sprintf(text, "Computer Boards library version %4.1f installed. \nYou must upgrade to version %4.1f",
            DLLNum, DESIREDREVISION);
    MessageBeep(MB_OK);
    MessageBox(0, text, "Initialisation Error", MB_ICONHAND);
    FreeLibrary(CBLibrary);
    CBLibrary = 0;
    return false;
  }



  myAConvertData = (int(__stdcall*)(short, long, unsigned short*, short*)) (int(__stdcall*)()) GetProcAddress(CBLibrary, "cbAConvertData");
  myACalibrateData = (int(__stdcall*)(short, long, int, unsigned short*)) (int(__stdcall*)()) GetProcAddress(CBLibrary, "cbACalibrateData");
  myAConvertPretrigData = (int(__stdcall*)(int, long, long, unsigned short*, unsigned short*)) GetProcAddress(CBLibrary, "cbAConvertPretrigData");
  myAIn = (int(__stdcall*)(int, int, int, unsigned short*)) GetProcAddress(CBLibrary, "cbAIn");
  myAInScan = (int(__stdcall*)(int, int, int, long, long*, int, HGLOBAL, int)) GetProcAddress(CBLibrary, "cbAInScan");
  myALoadQueue = (int(__stdcall*)(int, short*, short*, int)) GetProcAddress(CBLibrary, "cbALoadQueue");
  myAOut = (int(__stdcall*)(int, int, int, unsigned short)) GetProcAddress(CBLibrary, "cbAOut");
  myAOutScan = (int(__stdcall*)(int, int, int, long, long*, int, HGLOBAL, int)) GetProcAddress(CBLibrary, "cbAOutScan");
  myAPretrig = (int(__stdcall*)(int, int, int, long*, long*, long*, int, HGLOBAL, int)) GetProcAddress(CBLibrary, "cbAPretrig");
  myATrig = (int(__stdcall*)(int, int, int, unsigned short, int, unsigned short*)) GetProcAddress(CBLibrary, "cbATrig");
  myC8254Config = (int(__stdcall*)(int, int, int)) GetProcAddress(CBLibrary, "cbC8254Config");
  myC8536Config = (int(__stdcall*)(int, int, int, int, int)) GetProcAddress(CBLibrary, "cbC8536Config");
  myC9513Config = (int(__stdcall*)(int, int, int, int, int, int, int, int, int, int, int)) GetProcAddress(CBLibrary, "cbC9513Config");
  myC8536Init = (int(__stdcall*)(int, int, int)) GetProcAddress(CBLibrary, "cbC8536Init");
  myC9513Init = (int(__stdcall*)(int, int, int, int, int, int, int)) GetProcAddress(CBLibrary, "cbC9513Init");
  myCFreqIn = (int(__stdcall*)(int, int, int, unsigned short*, long*)) GetProcAddress(CBLibrary, "cbCFreqIn");
  myCIn = (int(__stdcall*)(int, int, unsigned short*)) GetProcAddress(CBLibrary, "cbCIn");
  myCStoreOnInt = (int(__stdcall*)(int, int, short*, HGLOBAL)) GetProcAddress(CBLibrary, "cbCStoreOnInt");
  myCLoad = (int(__stdcall*)(int, int, unsigned int)) GetProcAddress(CBLibrary, "cbCLoad");
  myDBitIn = (int(__stdcall*)(int, int, int, unsigned short*)) GetProcAddress(CBLibrary, "cbDBitIn");
  myDBitOut = (int(__stdcall*)(int, int, int, unsigned short)) GetProcAddress(CBLibrary, "cbDBitOut");
  myDConfigPort = (int(__stdcall*)(int, int, int)) GetProcAddress(CBLibrary, "cbDConfigPort");
  myDeclareRevision = (int(__stdcall*)(float*)) GetProcAddress(CBLibrary, "cbDeclareRevision");
  myDIn = (int(__stdcall*)(int, int, unsigned short*)) GetProcAddress(CBLibrary, "cbDIn");
  myDInScan = (int(__stdcall*)(int, int, long, long*, HGLOBAL, int)) GetProcAddress(CBLibrary, "cbDInScan");
  myDOut = (int(__stdcall*)(int, int, unsigned short)) GetProcAddress(CBLibrary, "cbDOut");
  myDOutScan = (int(__stdcall*)(int, int, long, long*, HGLOBAL, int)) GetProcAddress(CBLibrary, "cbDOutScan");
  myErrHandling = (int(__stdcall*)(int, int)) GetProcAddress(CBLibrary, "cbErrHandling");
  myFileAInScan = (int(__stdcall*)(int, int, int, long, long*, int, char*, int)) GetProcAddress(CBLibrary, "cbFileAInScan");
  myFileGetInfo = (int(__stdcall*)(char*, short*, short*, long*, long*, long*, int*)) GetProcAddress(CBLibrary, "cbFileGetInfo");
  myFilePretrig = (int(__stdcall*)(int, int, int, long*, long*, long*, int, char*, int)) GetProcAddress(CBLibrary, "cbFilePretrig");
  myFileRead = (int(__stdcall*)(char*, long, long*, unsigned short*)) GetProcAddress(CBLibrary, "cbFileRead");
  myGetErrMsg = (int(__stdcall*)(int, char*)) GetProcAddress(CBLibrary, "cbGetErrMsg");
  myGetStatus = (int(__stdcall*)(int, short*, long*, long*)) GetProcAddress(CBLibrary, "cbGetStatus");
  myRS485 = (int(__stdcall*)(int, int, int)) GetProcAddress(CBLibrary, "cbRS485");
  myStopBackground = (int(__stdcall*)(int)) GetProcAddress(CBLibrary, "cbStopBackground");
  myTIn = (int(__stdcall*)(int, int, int, float*, int)) GetProcAddress(CBLibrary, "cbTIn");
  myTInScan = (int(__stdcall*)(int, int, int, int, float*, int)) GetProcAddress(CBLibrary, "cbTInScan");
  myMemSetDTMode = (int(__stdcall*)(int, int)) GetProcAddress(CBLibrary, "cbMemSetDTMode");
  myMemReset = (int(__stdcall*)(int)) GetProcAddress(CBLibrary, "cbMemReset");
  myMemRead = (int(__stdcall*)(int, unsigned short*, long, long)) GetProcAddress(CBLibrary, "cbMemRead");
  myMemWrite = (int(__stdcall*)(int, unsigned short*, long, long)) GetProcAddress(CBLibrary, "cbMemWrite");
  myMemReadPretrig = (int(__stdcall*)(int, unsigned short*, long, long)) GetProcAddress(CBLibrary, "cbMemReadPretrig");
  myWinBufToArray = (int(__stdcall*)(HGLOBAL, unsigned short*, long, long)) GetProcAddress(CBLibrary, "cbWinBufToArray");
  myWinArrayToBuf = (int(__stdcall*)(unsigned short*, HGLOBAL, long, long)) GetProcAddress(CBLibrary, "cbWinArrayToBuf");
  myWinBufAlloc = (void*(__stdcall*)(long)) GetProcAddress(CBLibrary, "cbWinBufAlloc");
  myWinBufFree = (int(__stdcall*)(HGLOBAL)) GetProcAddress(CBLibrary, "cbWinBufFree");
  myInByte = (int(__stdcall*)(int, int)) GetProcAddress(CBLibrary, "cbInByte");
  myOutByte = (int(__stdcall*)(int, int, int)) GetProcAddress(CBLibrary, "cbOutByte");
  myInWord = (int(__stdcall*)(int, int)) GetProcAddress(CBLibrary, "cbInWord");
  myOutWord = (int(__stdcall*)(int, int, int)) GetProcAddress(CBLibrary, "cbOutWord");
  myGetConfig = (int(__stdcall*)(int, int, int, int, int*)) GetProcAddress(CBLibrary, "cbGetConfig");
  mySetConfig = (int(__stdcall*)(int, int, int, int, int)) GetProcAddress(CBLibrary, "cbSetConfig");
  myToEngUnits = (int(__stdcall*)(int, int, unsigned short, float*)) GetProcAddress(CBLibrary, "cbToEngUnits");
  myFromEngUnits = (int(__stdcall*)(int, int, float, unsigned short*)) GetProcAddress(CBLibrary, "cbFromEngUnits");
  myGetBoardName = (int(__stdcall*)(int, char*)) GetProcAddress(CBLibrary, "cbGetBoardName");
  //mySetTrigger = (int(__stdcall*)()) GetProcAddress(CBLibrary, "cbSetTrigger");

  return true;
}
void FreeCBDLL()
{
  if (!CBLibrary) return;
  FreeLibrary(CBLibrary);
  CBLibrary = 0;
}
