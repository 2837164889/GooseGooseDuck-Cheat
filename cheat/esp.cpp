#include "esp.hpp"
#include "cheat/gameManager.hpp"
#include "cheat/unityEngineCamera.hpp"
#include "utils.hpp"

// Only works if getGameState() == gameStateCode::InGame
void ESPMain(list<DWORD_PTR> PlayerControllerList, playerInfo player[], bool drawLine, bool drawBox, bool showPlayerInfo) {

	ImGuiIO& io = ImGui::GetIO(); (void)io;

	RECT wndRc;
	GetClientRect(FindWindow(0, L"Goose Goose Duck"), &wndRc);

	list<DWORD_PTR>::iterator ListIterator;
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y)); // GetClientRect()

	ImGui::Begin("Overlay", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoBackground);
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	int cnt = 0;
	Vector3 LocalPlayerPos = WorldToScreenPoint(player[0].pos);

	draw_list->AddText(ImVec2(LocalPlayerPos.x + 50.0f, wndRc.bottom - (LocalPlayerPos.y + 90.0f)), ImColor(1.0f, 1.0f, 1.0f, 1.0f), player[0].nickname);
	draw_list->AddText(ImVec2(LocalPlayerPos.x - 40.0f, wndRc.bottom - (LocalPlayerPos.y - 90.0f)), ImColor(1.0f, 1.0f, 1.0f, 1.0f), returnRoleName(player[0].playerRoleId));

	for (ListIterator = PlayerControllerList.begin(); ListIterator != PlayerControllerList.end(); ListIterator++) { // local-based-relative calculation needed.  linear interpolation

		if (!player[cnt].isLocal && !player[cnt].isGhost)
		{
			Vector3 targetPos = WorldToScreenPoint(player[cnt].pos);

			if (drawLine)
				draw_list->AddLine(ImVec2(LocalPlayerPos.x, wndRc.bottom - LocalPlayerPos.y), ImVec2(targetPos.x, wndRc.bottom - targetPos.y), ImColor(0.4f, 1.0f, 0.4f, 1.0f), 2.0f);

			if (drawBox)
				draw_list->AddRect(ImVec2(targetPos.x - 40.0f, wndRc.bottom - (targetPos.y - 70.0f)), ImVec2(targetPos.x + 40.0f, wndRc.bottom - (targetPos.y + 70.0f)), ImColor(0.5f, 0.0f, 0.0f, 1.0f), 0.0f, 0, 2.0f);

			if (showPlayerInfo) {
				draw_list->AddText(ImVec2(targetPos.x + 50.0f, wndRc.bottom - (targetPos.y + 50.0f)), ImColor(1.0f, 1.0f, 1.0f, 1.0f), player[cnt].nickname);
				draw_list->AddText(ImVec2(targetPos.x - 40.0f, wndRc.bottom - (targetPos.y - 50.0f)), ImColor(1.0f, 1.0f, 1.0f, 1.0f), returnRoleName(player[cnt].playerRoleId));
			}
		}
		cnt++;
	}
}