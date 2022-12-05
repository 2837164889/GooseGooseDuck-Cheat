#include "playerController.hpp"


typedef void* (_stdcall* tUpdate)(void* PlayerController);

tUpdate oUpdate;


playerInfo player[16]; // max player is 16.

list<DWORD_PTR> PlayerControllerList;
list<DWORD_PTR>::iterator ListIterator;

/*
-------------------------------------------------------------PLAN------------------------------------------------------------------------------
1. Handlers.GameHandlers.PlayerHandlers.LocalPlayer has a field called Player<PlayerController>. 0x18
2. And PlayerController has a filed called playersList.  Dictionary<string, PlayerController>. 0x10  STATIC FIELD........
3. I will use localPlayer instead of using the under codes.
4. This would be more stable.
5. The cheat no more crash the game by referencing wrong instance.
--------------------------------------------------------------------------------------------------------------------------------------------------
*/

tUpdate hkUpdate(void* PlayerController)
{
	if (getGameState() != gameStateCode::InGame) {
		static list<DWORD_PTR>::iterator tmpIter;
		tmpIter = std::find(PlayerControllerList.begin(), PlayerControllerList.end(), (DWORD_PTR)(PlayerController));

		if (tmpIter == PlayerControllerList.end()) {
			PlayerControllerList.push_back((DWORD_PTR)PlayerController);
		}

		int cnt = 0;

		for (ListIterator = PlayerControllerList.begin(); ListIterator != PlayerControllerList.end(); ListIterator++) {
			player[cnt].update(*ListIterator); // wrong reference issue
			player[cnt].updatePosition(*ListIterator);
			cnt++;
		}
	}
	else {
		for (int i = 0; i < PlayerControllerList.size(); i++) { player[i].reset(); }
		PlayerControllerList.clear();
	}

	return (tUpdate)oUpdate(PlayerController);
}

bool playerControllerHook() {
	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::PlayerController::updateRVA), hkUpdate, (void**)&oUpdate) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::PlayerController::updateRVA)) != MH_OK) {
		return false;
	}
	else
		return true;
}