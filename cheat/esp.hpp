#pragma once

#include "imgui/imgui.h"
#include "struct.hpp"
#include "offsets.hpp"
#include "cheat/cinemachine.hpp"

#include <Windows.h>
#include <list>

using namespace std;

void ESPMain(list<DWORD_PTR> PlayerControllerList, playerInfo player[], bool drawLine, bool drawBox, bool showPlayerInfo);