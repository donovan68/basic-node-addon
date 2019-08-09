#include <iostream>
#include <stdlib.h>
#include <napi.h>
#include <regex>
#include <windows.h>
#include <stdio.h>
#include "test.h"
#pragma comment(lib, "winmm.lib")



std::string test::hello()
{
	std::cout << "Playing WAV file : \n";
	PlaySound("C:\\RockyRoadBlues.wav", NULL, SND_FILENAME);
	std::cout << "Playing WAV file : \n";
	PlaySound("C:\\Hey_You.wav", NULL, SND_FILENAME);
    return "Hello World123";
}

Napi::String test::HelloWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, test::hello());
	
    return returnValue;
}

Napi::Object test::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(
        "hello", Napi::Function::New(env, test::HelloWrapped)
    );

    return exports;
}