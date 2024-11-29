
#include <windows.h>
#include <stdio.h>

#include "mycb.h"
#include "cbw.h"

int WINAPI (*myAConvertData) (short BoardNum, long int NumPoints, unsigned short *ADData, short *ChanTags);
int WINAPI (*myACalibrateData) (int BoardNum, long NumPoints, int Gain, unsigned FAR *ADData);
int WINAPI (*myAConvertPretrigData) (short BoardNum, long int PreTrigCount,
                 long int TotalCount, unsigned short *ADData, short *ChanTags);
int WINAPI (*myAIn) (short BoardNum, short Chan, short Gain,
                                                    unsigned short *DataValue);
int WINAPI (*myAInScan) (short BoardNum, short LowChan, short HighChan,
                                    long int Count, long int *Rate, short Gain,
                                    unsigned short MemHandle, short Options);
                                    /*
int WINAPI (*myALoadQueue) (short BoardNum, short *ChanArray,
                                    short *GainArray, unsigned short NumChans);
int WINAPI (*myAOut) (short BoardNum, short Chan, short Gain,
                                                     unsigned short DataValue);
int WINAPI (*myAOutScan) (short BoardNum, short LowChan, short HighChan,
                                    long int Count, long int *Rate, short Gain,
                                    unsigned short MemHandle, short Options);
int WINAPI (*myAPretrig) (short BoardNum, short LowChan, short HighChan,
                                  long int *PreTrigCount, long int *TotalCount,
                                  long int *Rate, short Gain,
                                  unsigned short MemHandle, short Options);
int WINAPI (*myATrig) (short BoardNum, short Chan, short TrigType,
              unsigned short TrigValue, short Gain, unsigned short *DataValue);
int WINAPI (*myC8254Config) (int BoardNum, int CounterNum, int Config);
int WINAPI (*myC8536Config) (int BoardNum, int CounterNum, int OutputControl,
                       int RecycleMode, int Retrigger);
int WINAPI (*myC9513Config) (int BoardNum, int CounterNum, int GateControl,
                       int CounterEdge, int CountSource, int SpecialGate,
                       int Reload, int RecycleMode, int BCDMode,
                       int CountDirection, int OutputControl);
int WINAPI (*myC8536Init) (int BoardNum, int ChipNum, int Ctr1Output);
int WINAPI (*myC9513Init) (int BoardNum, int ChipNum, int FOutDivider, int FOutSource,
                            int Compare1, int Compare2, int TimeOfDay);
int WINAPI (*myCFreqIn) (int BoardNum, int SigSource, int GateInterval,
                          unsigned FAR *Count, long FAR *Freq);
int WINAPI (*myCIn) (int BoardNum, int CounterNum, unsigned FAR *Count);
int WINAPI (*myCStoreOnInt) (int BoardNum, int IntCount, int FAR *CntrControl,
                              HGLOBAL MemHandle);
int WINAPI (*myCLoad) (int BoardNum, int RegNum, unsigned LoadValue);
*/
int WINAPI (*myDBitIn) (int BoardNum, int PortType, int BitNum, USHORT FAR *BitValue);
int WINAPI (*myDBitOut) (int BoardNum, int PortType, int BitNum, USHORT BitValue);
int WINAPI (*myDConfigPort) (int BoardNum, int PortNum, int Direction);
/*
int WINAPI (*myDeclareRevision) (float FAR *RevNum);
int WINAPI (*myDIn) (int BoardNum, int PortNum, unsigned FAR *DataValue);
int WINAPI (*myDInScan) (int BoardNum, int PortNum, long Count, long FAR *Rate,
                          HGLOBAL MemHandle, int Options);
int WINAPI (*myDOut) (int BoardNum, int PortNum, unsigned DataValue);
int WINAPI (*myDOutScan) (int BoardNum, int PortNum, long Count, long FAR *Rate,
                           HGLOBAL MemHandle, int Options);
int WINAPI (*myErrHandling) (int ErrReporting, int ErrHandling);
int WINAPI (*myFileAInScan) (int BoardNum, int LowChan, int HighChan,
                              long Count, long FAR *Rate, int Gain,
                              char FAR *FileName, int Options);
int WINAPI (*myFileGetInfo) (char FAR *FileName, int FAR *LowChan,
                              int FAR *HighChan, long FAR *PreTrigCount,
                              long FAR *TotalCount, long FAR *Rate,
                              int FAR *Gain);
int WINAPI (*myFilePretrig) (int BoardNum, int LowChan, int HighChan,
                              long FAR *PreTrigCount, long FAR *TotalCount,
                              long FAR *Rate, int Gain, char FAR *FileName,
                              int Options);
int WINAPI (*myFileRead) (char FAR *FileName, long FirstPoint, long FAR *NumPoints,
                           unsigned FAR *DataBuffer);
                           */
int WINAPI (*myGetErrMsg) (int ErrCode, char FAR *ErrMsg);
int WINAPI (*myGetRevision) (float FAR *DLLRevNum, float FAR *VXDRevNum);
/*
int WINAPI (*myGetStatus) (int BoardNum, int FAR *Status, long FAR *CurCount,
                            long FAR *CurIndex);
int WINAPI (*myRS485) (int BoardNum, int Transmit, int Receive);
int WINAPI (*myStopBackground) (int BoardNum);
int WINAPI (*myTIn) (int BoardNum, int Chan, int Scale, float FAR *TempValue,
                      int Options);
int WINAPI (*myTInScan) (int BoardNum, int LowChan, int HighChan, int Scale,
                   float FAR *DataBuffer, int Options);
int WINAPI (*myMemSetDTMode) (int BoardNum, int Mode);
int WINAPI (*myMemReset) (int BoardNum);
int WINAPI (*myMemRead) (int BoardNum, unsigned FAR *DataBuffer,
                          long FirstPoint, long Count);
int WINAPI (*myMemWrite) (int BoardNum, unsigned FAR *DataBuffer,
                           long FirstPoint, long Count);
int WINAPI (*myMemReadPretrig) (int BoardNum, unsigned FAR *DataBuffer,
                                 long FirstPoint, long Count);
int WINAPI (*myWinBufToArray) (HGLOBAL MemHandle, unsigned FAR *DataArray, long StartPt,
                                long Count);
int WINAPI (*myWinArrayToBuf) (unsigned FAR *DataArray, HGLOBAL MemHandle, long StartPt,
                                long Count);
HGLOBAL WINAPI (*myWinBufAlloc) (long NumPoints);
int WINAPI (*myWinBufFree) (HGLOBAL MemHandle);
int WINAPI (*myInByte) (int BoardNum, int PortNum);
int WINAPI (*myOutByte) (int BoardNum, int PortNum, int PortVal);
int WINAPI (*myInWord) (int BoardNum, int PortNum);
int WINAPI (*myOutWord) (int BoardNum, int PortNum, int PortVal);
int WINAPI (*myGetConfig) (int InfoType, int BoardNum, int DevNum, int ConfigItem, int FAR *ConfigVal);
int WINAPI (*mySetConfig) (int InfoType, int BoardNum, int DevNum, int ConfigItem, int ConfigVal);
*/
int WINAPI (*myToEngUnits) (int BoardNum, int Range, unsigned DataVal, float FAR *EngUnits);
int WINAPI (*myFromEngUnits) (int BoardNum, int Range, float EngUnits, unsigned FAR *DataVal);
int WINAPI (*myGetBoardName) (int BoardNum, char FAR *BoardName);
/*
int WINAPI (*mySetTrigger) (int BoardNum, int TrigType, int LowThreshold, int HighThreshold);
*/
