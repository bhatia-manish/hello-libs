/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <cstring>
#include <jni.h>
#include <cinttypes>
#include <android/log.h>
#include <gmath.h>
#include <gperf.h>
#include <string>
#include <essentia/streamutil.h>
//#include <essentia/constantq.h>
#include <essentia/algorithmfactory.h>
#include <essentia/pool.h>


using namespace std;
using namespace essentia;
using namespace standard;


#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, "hello-libs::", __VA_ARGS__))

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   app/src/main/java/com/example/hellolibs/MainActivity.java
 */
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hellolibs_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // Just for simplicity, we do this right away; correct way would do it in
    // another thread...
///

    __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", "Log");
    double _sampleRate=16000;
    double _minFrequency=27.5;
    double _maxFrequency = 4186.005;
    unsigned int _binsPerOctave=36;
    double _threshold=0.005;
    essentia::init();


    AlgorithmFactory& factory = AlgorithmFactory::instance();



    Algorithm* _constantq = AlgorithmFactory::create("ConstantQ");

    _constantq->configure("minFrequency", _minFrequency,
                          "maxFrequency", _maxFrequency,
                          "binsPerOctave", _binsPerOctave,
                          "sampleRate", _sampleRate,
                          "threshold", _threshold);

//
//    ConstantQ *constantQ = new ConstantQ();
//
//
    _constantq->compute();







    return env->NewStringUTF("Hello from JNI LIBS!");
}
