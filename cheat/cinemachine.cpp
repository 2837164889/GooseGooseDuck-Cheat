#include "cinemachine.hpp"

tCineDamp oCineDamp;
Vector3 initial;

tCineDamp hkCineDamp(void* somthing, Vector3 d_param1, Vector3 d_param2, float d_t) {
	initial = d_param1;
	return (tCineDamp)oCineDamp(somthing, d_param1, d_param2, d_t);
}

Vector3 getDampFirstParam() { // super strong name~
	return initial;
}

bool CineMachineHook() {
	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::cinemachine::fn_damp), hkCineDamp, (void**)&oCineDamp) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::cinemachine::fn_damp)) != MH_OK) {
		return false;
	}
	else
		return true;
}