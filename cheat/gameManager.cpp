#include "gameManager.hpp"

typedef void* (_stdcall* tGMUpdate)(void* GameManager);

tGMUpdate oGMUpdate;
DWORD_PTR gm;

tGMUpdate hkGMUpdate(void* GameManager) {
	gm = (DWORD_PTR)GameManager;
	return (tGMUpdate)oGMUpdate(GameManager);
}

bool GameManagerHook() {
	if (MH_CreateHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::GameManager::fn_update), hkGMUpdate, (void**)&oGMUpdate) != MH_OK
		|| MH_EnableHook((void*)(GetGameAssemblyBase(L"GameAssembly.dll") + GooseGooseDuck::GameManager::fn_update)) != MH_OK) {
		return false;
	}
	else
		return true;
}

int getGameState() {
#define GET_INT_VALUE(X) *(int*)(gm+X)
	int state = GET_INT_VALUE(GooseGooseDuck::GameManager::fl_gameState);
	return state;
#undef GET_INT_VALUE
}

DWORD_PTR getGMIns() {
	return gm;
}

/*
public enum MHIEPEJEFEB
		{
			// Token: 0x04001BF9 RID: 7161
			[Token(Token = "0x4001BF9")]
			InLobby,
			// Token: 0x04001BFA RID: 7162
			[Token(Token = "0x4001BFA")]
			Drafting,
			// Token: 0x04001BFB RID: 7163
			[Token(Token = "0x4001BFB")]
			InGame,
			// Token: 0x04001BFC RID: 7164
			[Token(Token = "0x4001BFC")]
			Opening,
			// Token: 0x04001BFD RID: 7165
			[Token(Token = "0x4001BFD")]
			Discussion,
			// Token: 0x04001BFE RID: 7166
			[Token(Token = "0x4001BFE")]
			Voting,
			// Token: 0x04001BFF RID: 7167
			[Token(Token = "0x4001BFF")]
			Waiting,
			// Token: 0x04001C00 RID: 7168
			[Token(Token = "0x4001C00")]
			Proceeding
		}
*/