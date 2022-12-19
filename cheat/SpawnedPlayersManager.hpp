#pragma once

#include "struct.hpp"
#include "utils.hpp"
#include "MinHook/include/MinHook.h"
#include "gameManager.hpp"

using namespace std;

bool SpawnedPlayersManagerHook();
DWORD_PTR getSpawnedPlayersManagerInstance();