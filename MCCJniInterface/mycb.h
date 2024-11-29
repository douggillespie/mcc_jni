#if !defined(mycb_h)
#define mycb_h


#define MAXCOMPUTERBOARDS 10     
#include <windows.h>
#include "systypes.h"


#define STRAUXPORT          "AUXPORT"
#define STRFIRSTPORTA       "FIRSTPORTA"
#define STRFIRSTPORTB       "FIRSTPORTB"
#define STRFIRSTPORTCL      "FIRSTPORTCL"
#define STRFIRSTPORTCH      "FIRSTPORTCH"
#define STRSECONDPORTA      "SECONDPORTA"
#define STRSECONDPORTB      "SECONDPORTB"
#define STRSECONDPORTCL     "SECONDPORTCL"
#define STRSECONDPORTCH     "SECONDPORTCH"
#define STRTHIRDPORTA       "THIRDPORTA"
#define STRTHIRDPORTB       "THIRDPORTB"
#define STRTHIRDPORTCL      "THIRDPORTCL"
#define STRTHIRDPORTCH      "THIRDPORTCH"
#define STRFOURTHPORTA      "FOURTHPORTA"
#define STRFOURTHPORTB      "FOURTHPORTB"
#define STRFOURTHPORTCL     "FOURTHPORTCL"
#define STRFOURTHPORTCH     "FOURTHPORTCH"
#define STRFIFTHPORTA       "FIFTHPORTA"
#define STRFIFTHPORTB       "FIFTHPORTB"
#define STRFIFTHPORTCL      "FIFTHPORTCL"
#define STRFIFTHPORTCH      "FIFTHPORTCH"
#define STRSIXTHPORTA       "SIXTHPORTA"
#define STRSIXTHPORTB       "SIXTHPORTB"
#define STRSIXTHPORTCL      "SIXTHPORTCL"
#define STRSIXTHPORTCH      "SIXTHPORTCH"
#define STRSEVENTHPORTA     "SEVENTHPORTA"
#define STRSEVENTHPORTB     "SEVENTHPORTB"
#define STRSEVENTHPORTCL    "SEVENTHPORTCL"
#define STRSEVENTHPORTCH    "SEVENTHPORTCH"
#define STREIGHTHPORTA      "EIGHTHPORTA"
#define STREIGHTHPORTB      "EIGHTHPORTB"
#define STREIGHTHPORTCL     "EIGHTHPORTCL"
#define STREIGHTHPORTCH     "EIGHTHPORTCH"


char* GetCBPortName(int port);
bool HaveCBDLL();
bool LoadCBDLL();
void FreeCBDLL();
int myCbNBits(int BoardNum);
bool ReadCBAnalogValue(int BoardNum, int ChanNum, int Gain, float* Val);  
bool ReadCBDigitalValue(int BoardNum, int ChanNum, uint16* pValue);       
bool SetCBDigitalValue(int BoardNum, int ChanNum, int pValue);          
int cbRangeFromGain(int gain);
                                                                                                      
extern int  (*myAtData) (int BoardNum, int NumPoints, int *ADData, int *ChanTags);

extern int WINAPI (*myAConvertData) (short BoardNum, long int NumPoints, unsigned short *ADData, short *ChanTags);
extern int WINAPI (*myACalibrateData) (int BoardNum, long NumPoints, int Gain, unsigned FAR *ADData);
extern int WINAPI (*myAConvertPretrigData) (short BoardNum, long int PreTrigCount,
                 long int TotalCount, unsigned short *ADData, short *ChanTags);
extern int WINAPI (*myAIn) (short BoardNum, short Chan, short Gain,
                                                    unsigned short *DataValue);
extern int WINAPI (*myAInScan) (short BoardNum, short LowChan, short HighChan,
                                    long int Count, long int *Rate, short Gain,
                                    unsigned short MemHandle, short Options);
                                    /*
extern int WINAPI (*myALoadQueue) (short BoardNum, short *ChanArray,
                                    short *GainArray, unsigned short NumChanss);
extern int WINAPI (*myAOut) (short BoardNum, short Chan, short Gain,
                                                     unsigned short DataValue);
extern int WINAPI (*myAOutScan) (short BoardNum, short LowChan, short HighChan,
                                    long int Count, long int *Rate, short Gain,
                                    unsigned short MemHandle, short Options);
extern int WINAPI (*myAPretrig) (short BoardNum, short LowChan, short HighChan,
                                  long int *PreTrigCount, long int *TotalCount,
                                  long int *Rate, short Gain,
                                  unsigned short MemHandle, short Options);
extern int WINAPI (*myATrig) (short BoardNum, short Chan, short TrigType,
              unsigned short TrigValue, short Gain, unsigned short *DataValue);
extern int WINAPI (*myC8254Config) (int BoardNum, int CounterNum, int Config);
extern int WINAPI (*myC8536Config) (int BoardNum, int CounterNum, int OutputControl,
                       int RecycleMode, int Retrigger);
extern int WINAPI (*myC9513Config) (int BoardNum, int CounterNum, int GateControl,
                       int CounterEdge, int CountSource, int SpecialGate,
                       int Reload, int RecycleMode, int BCDMode,
                       int CountDirection, int OutputControl);
extern int WINAPI (*myC8536Init) (int BoardNum, int ChipNum, int Ctr1Output);
extern int WINAPI (*myC9513Init) (int BoardNum, int ChipNum, int FOutDivider, int FOutSource,
                            int Compare1, int Compare2, int TimeOfDay);
extern int WINAPI (*myCFreqIn) (int BoardNum, int SigSource, int GateInterval,
                          USHORT *Count, long *Freq);
extern int WINAPI (*myCIn) (int BoardNum, int CounterNum, USHORT *Count);
extern int WINAPI (*myCStoreOnInt) (int BoardNum, int IntCount, short *CntrControl,
                              HGLOBAL MemHandle);
extern int WINAPI (*myCLoad) (int BoardNum, int RegNum, unsigned int LoadValue);
*/
extern int WINAPI (*myDBitIn) (int BoardNum, int PortType, int BitNum, USHORT *BitValue);
extern int WINAPI (*myDBitOut) (int BoardNum, int PortType, int BitNum, USHORT BitValue);
extern int WINAPI (*myDConfigPort) (int BoardNum, int PortNum, int Direction);
/*
extern int WINAPI (*myDeclareRevision) (float *RevNum);
extern int WINAPI (*myDIn) (int BoardNum, int PortNum, USHORT *DataValue);
extern int WINAPI (*myDInScan) (int BoardNum, int PortNum, long Count, long *Rate,
                          HGLOBAL MemHandle, int Options);
extern int WINAPI (*myDOut) (int BoardNum, int PortNum, USHORT DataValue);
extern int WINAPI (*myDOutScan) (int BoardNum, int PortNum, long Count, long *Rate,
                           HGLOBAL MemHandle, int Options);
extern int WINAPI (*myErrHandling) (int ErrReporting, int ErrHandling);
extern int WINAPI (*myFileAInScan) (int BoardNum, int LowChan, int HighChan,
                              long Count, long *Rate, int Gain,
                              char *FileName, int Options);
extern int WINAPI (*myFileGetInfo) (char *FileName, short *LowChan,
                              short *HighChan, long *PreTrigCount,
                              long *TotalCount, long *Rate,
                              int *Gain);
extern int WINAPI (*myFilePretrig) (int BoardNum, int LowChan, int HighChan,
                              long *PreTrigCount, long *TotalCount,
                              long *Rate, int Gain, char *FileName,
                              int Options);
extern int WINAPI (*myFileRead) (char *FileName, long FirstPoint, long *NumPoints,
                           USHORT *DataBuffer);
*/
extern int WINAPI (*myGetErrMsg) (int ErrCode, char *ErrMsg);
extern int WINAPI (*myGetRevision) (float *DLLRevNum, float *VXDRevNum);
/*
extern int WINAPI (*myGetStatus) (int BoardNum, short *Status, long *CurCount,
                            long *CurIndex);
extern int WINAPI (*myRS485) (int BoardNum, int Transmit, int Receive);
extern int WINAPI (*myStopBackground) (int BoardNum);
extern int WINAPI (*myTIn) (int BoardNum, int Chan, int Scale, float *TempValue,
                      int Options);
extern int WINAPI (*myTInScan) (int BoardNum, int LowChan, int HighChan, int Scale,
                   float *DataBuffer, int Options);
extern int WINAPI (*myMemSetDTMode) (int BoardNum, int Mode);
extern int WINAPI (*myMemReset) (int BoardNum);
extern int WINAPI (*myMemRead) (int BoardNum, USHORT *DataBuffer,
                          long FirstPoint, long Count);
extern int WINAPI (*myMemWrite) (int BoardNum, USHORT *DataBuffer,
                           long FirstPoint, long Count);
extern int WINAPI (*myMemReadPretrig) (int BoardNum, USHORT *DataBuffer,
                                 long FirstPoint, long Count);
extern int WINAPI (*myWinBufToArray) (HGLOBAL MemHandle, USHORT *DataArray, long StartPt,
                                long Count);
extern int WINAPI (*myWinArrayToBuf) (USHORT *DataArray, HGLOBAL MemHandle, long StartPt,
                                long Count);
extern HGLOBAL WINAPI (*myWinBufAlloc) (long NumPoints);
extern int WINAPI (*myWinBufFree) (HGLOBAL MemHandle);
extern int WINAPI (*myInByte) (int BoardNum, int PortNum);
extern int WINAPI (*myOutByte) (int BoardNum, int PortNum, int PortVal);
extern int WINAPI (*myInWord) (int BoardNum, int PortNum);
extern int WINAPI (*myOutWord) (int BoardNum, int PortNum, int PortVal);
extern int WINAPI (*myGetConfig) (int InfoType, int BoardNum, int DevNum, int ConfigItem, int *ConfigVal);
extern int WINAPI (*mySetConfig) (int InfoType, int BoardNum, int DevNum, int ConfigItem, int ConfigVal);
*/
extern int WINAPI (*myToEngUnits) (int BoardNum, int Range, unsigned DataVal, float FAR *EngUnits);
extern int WINAPI (*myFromEngUnits) (int BoardNum, int Range, float EngUnits, unsigned FAR *DataVal);
extern int WINAPI (*myGetBoardName) (int BoardNum, char *BoardName);
/*
extern int WINAPI (*mySetTrigger) (int BoardNum, int TrigType, USHORT LowThreshold, USHORT HighThreshold);
*/
#endif
