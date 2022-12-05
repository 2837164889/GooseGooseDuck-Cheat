#include "unityEngineCamera.hpp"

tWorldToScreenPoint oWorldToScreenPoint;

void* ins;

Vector3 hkWorldToScreenPoint(void* instance, Vector3 position) {
	if (getGameState() == gameStateCode::InGame) ins = instance;  // Use WndProc uMsg for condition.
	else ins = 0;

	return oWorldToScreenPoint(instance, position);
}

Vector3 WorldToScreenPoint(Vector3 pos) {
	return oWorldToScreenPoint(ins, pos);
}

bool isCameraInstanceSet() {
	if (ins == 0) return false;
	else return true;
}

bool unityEngineCameraHook() {
	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::WorldToScreenPoint), hkWorldToScreenPoint, (void**)&oWorldToScreenPoint) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::WorldToScreenPoint)) != MH_OK) {
		return false;
	}
	else
		return true;
}