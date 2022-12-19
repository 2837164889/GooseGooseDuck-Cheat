#pragma once

#include "struct.hpp"
#include "utils.hpp"
#include "gameManager.hpp"
#include "MinHook/include/MinHook.h"

using namespace std;

bool localPlayerHook();
DWORD_PTR getLocalPlayerInstance();