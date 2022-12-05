#include "localPlayer.hpp"

typedef void* (_stdcall* tLPUpdate)(void* instance);

tLPUpdate oLPUpdate;

DWORD_PTR ins;

tLPUpdate hkLPUpdate(void* instance) {
	ins = (DWORD_PTR)instance;
	return (tLPUpdate)oLPUpdate(instance);
}

DWORD_PTR getLocalPlayerInstance() {
	return ins;
}

bool localPlayerHook() {
	if(MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::localPlayer::update), hkLPUpdate, (void**)&oLPUpdate) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::localPlayer::update)) != MH_OK) {
	return false;
}
	else
	return true;
}