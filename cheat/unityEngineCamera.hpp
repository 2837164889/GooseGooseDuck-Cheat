#pragma once

#include "struct.hpp"
#include "utils.hpp"
#include "MinHook/include/MinHook.h"
#include "gameManager.hpp"

using namespace std;

typedef Vector3 (*tWorldToScreenPoint)(void* instance, Vector3 position);
typedef float* (*tSet_worldToCameraMatrix)(void*);

Vector3 WorldToScreenPoint(Vector3 pos);
bool unityEngineCameraHook();
float* retMat();