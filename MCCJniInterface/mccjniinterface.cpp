
//#include <vcl.h>
#include <windows.h>
#include <math.h>
#include <jni.h>
//#include <jni.h>
#include "mcc_MccJniInterface.h"
#include "cbw.h"
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

int lastError = 0;

JNIEXPORT jboolean JNICALL Java_mcc_MccJniInterface_haveLibrary
	  (JNIEnv *, jclass)
	  {
	  	return (jboolean) true; //LoadCBDLL();
	  }

/*
 * Class:     mcc_MccGniInterface
 * Method:    getNumBoards
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_mcc_MccJniInterface_jniGetNumBoards
  (JNIEnv *, jclass)
  {
  	return (jint) 1;
  }

/*
 * Class:     mcc_MccGniInterface
 * Method:    getBoardName
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_mcc_MccJniInterface_jniGetBoardName
  (JNIEnv *env, jclass, jint iBoard) {
  	char name[200];
  	cbGetBoardName((int) iBoard, name);
  	return env->NewStringUTF(name);
  }

/**
 *
 */
JNIEXPORT jdouble JNICALL Java_mcc_MccJniInterface_jniReadVoltage
  (JNIEnv *env, jclass, jint iBoard, jint iChannel, jint gain) {
	float dataValue = 0;
	lastError = cbVIn(iBoard, iChannel, gain, &dataValue, 0);
	if (lastError == 0) {
		return (jdouble) dataValue;
	}
	else {
		return MCCERRORVALUE;
	}
}

/**
 * Get the last error code from whatever operation was performed.
 */
JNIEXPORT jint JNICALL Java_mcc_MccJniInterface_jniGetLastErrorCode
  (JNIEnv *env, jclass) {
	return lastError;
}

/**
 * Get a cb error string from an error code.
 */
JNIEXPORT jstring JNICALL Java_mcc_MccJniInterface_jniGetErrorString
  (JNIEnv *env, jclass, jint errorCode) {
	char errorMessage[ERRSTRLEN];
	lastError = cbGetErrMsg(errorCode, errorMessage);
	if (lastError == 0) {
	  	return env->NewStringUTF(errorMessage);
	}
}

