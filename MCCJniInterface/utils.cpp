//#include "owl\pch.h"

#include <windows.h>
#include <stdio.h>

#include "mycb.h"
#include "cbw.h"
                                    
char* GetCBPortName(int port)
{
  switch(port)
  {
    case AUXPORT:
      return "AUXPORT";
    case FIRSTPORTA:
      return "FIRSTPORTA";
    case FIRSTPORTB:
      return "FIRSTPORTB";
    case SECONDPORTA:
      return "SECONDPORTA";
    case SECONDPORTB:
      return "SECONDPORTB";
    case THIRDPORTA:
      return "THIRDPORTA";
    case THIRDPORTB:
      return "THIRDPORTB";
    case FOURTHPORTA:
      return "FOURTHPORTA";
    case FOURTHPORTB:
      return "FOURTHPORTB";
    case FIFTHPORTA:
      return "FIFTHPORTA";
    case FIFTHPORTB:
      return "FIFTHPORTB";
    case SIXTHPORTA:
      return "SIXTHPORTA";
    case SIXTHPORTB:
      return "SIXTHPORTB";
    case SEVENTHPORTA:
      return "SEVENTHPORTA";
    case SEVENTHPORTB:
      return "SEVENTHPORTB";
    case EIGHTHPORTA:
      return "EIGHTHPORTA";
    case EIGHTHPORTB:
      return "EIGHTHPORTB";
    default:
      return "Unknown Port";
  }
}
// a few routines which may be of use ....  
#define BOARDNAMELEN       25
int myCbNBits(int BoardNum)
{
  return 12;
  if (HaveCBDLL() == false) return 0;
  // check there is actually a board installed
  char BoardName[BOARDNAMELEN+1];
  (*myGetBoardName) (BoardNum, BoardName);
  if (strcmp(BoardName, "Not Installed") == 0){
    return 0;
  }
  
  // see how many bits the card has by looking at the board name,
  // just after the first forward slash '/'
  short bits;
  char* slashpos;
  slashpos = strchr(BoardName, '/');
  if (slashpos == NULL){
    return 0;
  }
  sscanf(slashpos+1, "%2d", &bits);
  if (bits != 16) bits = 12;

  return bits;
}               
bool ReadCBAnalogValue(int BoardNum, int ChanNum, int Gain, float* pVal)
{
  if (!HaveCBDLL()) return false;
  int RetVal;
  unsigned short DataValue;
  if ((RetVal = (*myAIn)(BoardNum, ChanNum, BIP10VOLTS, &DataValue)) != 0) return false;
  if ((RetVal = (*myToEngUnits)(BoardNum, BIP10VOLTS, DataValue, pVal)) != 0) return false;
  return true;
}
bool ReadCBDigitalValue(int BoardNum, int ChanNum, uint16* pValue)
{  
  if (!HaveCBDLL()) return false;
  int BitValue;
  int RetVal;
  RetVal = (*myDConfigPort)(BoardNum, FIRSTPORTA, DIGITALIN);
  if ((RetVal = (*myDBitIn)(BoardNum, FIRSTPORTA, ChanNum, pValue)) != 0) return false;
  //*pValue = (int16) BitValue;
  return true;
}   
bool SetCBDigitalValue(int BoardNum, int ChanNum, int Value)
{  
  if (!HaveCBDLL()) return false;
  int BitValue;
  int RetVal;
  if ((RetVal = (*myDBitOut)(BoardNum, AUXPORT, ChanNum, Value)) != 0) return false;
  //*pValue = (int16) BitValue;
  return true;
}