//https://github.com/jjuiddong/Introduction-to-3D-Game-Programming-With-DirectX11/blob/master/Chapter%206%20Drawing%20in%20Direct3D/Box/BoxDemo.cpp
//https://github.com/guided-hacking/GH_D3D11_Hook/tree/master/GH_D3D11_Hook

#pragma once

#include "GameData.hpp"

//#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>
#include <Psapi.h>

DWORD_PTR GetGameAssemblyBase(const wchar_t* targetModuleName);
const char* returnRoleName(int id);
