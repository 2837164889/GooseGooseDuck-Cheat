#include "SpawnedPlayersManager.hpp"

typedef void* (_stdcall* tASP)(void* instance, void* string, void* SpawnedPlayerHandler);

tASP oASP;
DWORD_PTR aspIns;

tASP hkASP(void* instance, void* string, void* SpawnedPlayerHandler) {
	aspIns = (DWORD_PTR)instance;
	return (tASP)oASP(instance, string, SpawnedPlayerHandler);
}


DWORD_PTR getSpawnedPlayersManagerInstance()
{
	//if (getGameState() != gameStateCode::InLobby)
		return aspIns;
	//else
	//	return 0;
}

bool SpawnedPlayersManagerHook()
{
	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::SpawnedPlayersManager::fn_AddSpawnedPlayer), hkASP, (void**)&oASP) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::SpawnedPlayersManager::fn_AddSpawnedPlayer)) != MH_OK) {
		return false;
	}
	else
		return true;
}