#pragma once

#include "struct.hpp"
#include "utils.hpp"
#include "MinHook/include/MinHook.h"

using namespace std;

typedef void* (_stdcall* tCineDamp)(void* sth, Vector3 param1,Vector3 param2, float t);

bool CineMachineHook();
Vector3 getDampFirstParam();