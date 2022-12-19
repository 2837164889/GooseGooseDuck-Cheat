#pragma once

#include "offsets.hpp"
#include "utils.hpp"
#include "MinHook/include/MinHook.h"

int getGameState();
bool GameManagerHook();
DWORD_PTR getGMIns();