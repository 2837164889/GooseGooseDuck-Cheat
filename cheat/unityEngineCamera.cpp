#include "unityEngineCamera.hpp"

tWorldToScreenPoint oWorldToScreenPoint;
tSet_worldToCameraMatrix oSet_worldToCameraMatrix;

void* CamIns;
float* Matrix4x4;


Vector3 hkWorldToScreenPoint(void* instance, Vector3 position) {
	CamIns = instance;
	return oWorldToScreenPoint(instance, position);
}

// We don't need to click screen anymore to activate ESP!! :)))))))
float* hkSet_worldToCameraMatrix(void* instance) {
	Matrix4x4 = oSet_worldToCameraMatrix(instance);
	return Matrix4x4;
}

Vector3 WorldToScreenPoint(Vector3 pos) {
	return oWorldToScreenPoint(CamIns, pos);
}

float* retMat() {
	return Matrix4x4;
}

bool unityEngineCameraHook() {

	bool hooked_well = true;

	//oWorldToScreenPoint = (tWorldToScreenPoint)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::fn_WorldToScreenPoint);

	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::fn_set_worldToCameraMatrix), hkSet_worldToCameraMatrix, (void**)&oSet_worldToCameraMatrix) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::fn_set_worldToCameraMatrix)) != MH_OK) {
		hooked_well = false;
	}

	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::fn_WorldToScreenPoint), hkWorldToScreenPoint, (void**)&oWorldToScreenPoint) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::unityEngineCamera::fn_WorldToScreenPoint)) != MH_OK) {
		hooked_well = false;
	}

	return hooked_well;
	
}