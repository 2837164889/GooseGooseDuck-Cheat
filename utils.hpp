//https://github.com/jjuiddong/Introduction-to-3D-Game-Programming-With-DirectX11/blob/master/Chapter%206%20Drawing%20in%20Direct3D/Box/BoxDemo.cpp
//https://github.com/guided-hacking/GH_D3D11_Hook/tree/master/GH_D3D11_Hook

#pragma once

#include "GameData.hpp"
#include "struct.hpp"

//#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>
#include <Psapi.h>

//https://stackoverflow.com/questions/1429336/cross-referencing-included-headers-in-c-program
struct Vector3;
struct Vector2;

DWORD_PTR GetGameAssemblyBase(const wchar_t* targetModuleName);
const char* returnRoleName(int id);
bool WorldToScreen(Vector3 pos, Vector2& screen, float Matrix[16], int windowWidth, int windowHeight);