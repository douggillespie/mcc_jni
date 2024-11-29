# mcc_jni

Acquisition of data from [MeasurementComputing](https://www.measurementsystems.co.uk/measurement-computing)
devices

Copy of old code from r6279 on Sourceforge SVN site

Probably last built with mingw

JNI Interface to allow [PAMGuard](http://www.pamguard.org) to get data from 
Measurement Computing devices. Used by PAMGuard to read depth sensors and 
some other 'slow' readout devices. 

Distributed with PAMGuard as lib64/mccjniinterface.dll. JNI Java code is in
PAMGuard package mcc.MccJniInterface

Not planning further developments. Probably easier to access these boards
through JNA rather than JNI. 