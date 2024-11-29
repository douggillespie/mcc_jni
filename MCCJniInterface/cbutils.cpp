
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
  /*
     Ideally we need to work out here whether the board is configured for
     differential or single ended input. If it's single ended, then its only
     going to work on BIP10VOLTS - but that's really not good since
     it's only 11 bit and only has the one gain setting. If it's differential, then
     we get the full 12 bits and can also use other gain ranges.
  */
  // convert the gain into one of the CB units - 1 = BIP10VOLTS
  int range = cbRangeFromGain(Gain);
  /*
    Try to read it using the selected range, if that doens't work and the
    error is BADRANGE, and the range is not BIP10VOLTS, then ry
    with BIP10VOLTS, called in such a way that we don't get stuck in
    an endless loop !
  */

  if ((RetVal = (*myAIn)(BoardNum, ChanNum, range, &DataValue)) != 0) {
    if (RetVal == BADRANGE && range != BIP10VOLTS) {
      return ReadCBAnalogValue(BoardNum, ChanNum, 1, pVal);
    }
    else {
      // have either already tried with BIP10VOLTS, or there was some other error so give up
      return false;
    }
  }
  if ((RetVal = (*myToEngUnits)(BoardNum, range, DataValue, pVal)) != 0) return false;

  return true;
}
int cbRangeFromGain(int gain) {
  switch (gain) {
    case -1:
      return BIP20VOLTS;  // BIP20VOLTS doesn't seem to exist.
    case 0:
      return BIP10VOLTS;
    case 1:
      return BIP10VOLTS;
    case 2:
      return BIP5VOLTS;
    case 4:
      return BIP2PT5VOLTS;
    case 5:
      return BIP2VOLTS;
    case 10:
      return BIP1VOLTS;
    case 20:
      return BIPPT5VOLTS;
    case 40:
      return BIPPT25VOLTS;
    case 50:
      return BIPPT2VOLTS;
    case 100:
      return BIPPT1VOLTS;
    case 200:
      return BIPPT05VOLTS;
    case 1000:
      return BIPPT01VOLTS;
    case 2000:
      return BIPPT005VOLTS;
    default:
      return BIP10VOLTS;
  }
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