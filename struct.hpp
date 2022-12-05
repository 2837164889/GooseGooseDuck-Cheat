#pragma once

#include "imgui/imgui.h"
#include "offsets.hpp"
#include "cheat/gameManager.hpp"
#include "GameData.hpp"
#include "utils.hpp"
#include <Windows.h>

// from imgui_demo.cpp
struct ExampleAppLog
{
	ImGuiTextBuffer     Buf;
	ImVector<int>       LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
	bool                AutoScroll;  // Keep scrolling if already at the bottom.

	ExampleAppLog()
	{
		AutoScroll = true;
		Clear();
	}

	void Clear()
	{
		Buf.clear();
		LineOffsets.clear();
		LineOffsets.push_back(0);
	}

	void AddLog(const char* fmt, ...) IM_FMTARGS(2)
	{
		int old_size = Buf.size();
		va_list args;
		va_start(args, fmt);
		Buf.appendfv(fmt, args);
		va_end(args);
		for (int new_size = Buf.size(); old_size < new_size; old_size++)
			if (Buf[old_size] == '\n')
				LineOffsets.push_back(old_size + 1);
	}

	void Draw(const char* title, bool* p_open = NULL)
	{
		if (!ImGui::Begin(title, p_open))
		{
			ImGui::End();
			return;
		}

		// Options menu
		ImGui::Checkbox(u8"自动滚条", &AutoScroll);

		// Main window
		ImGui::SameLine();
		bool clear = ImGui::Button(u8"清除");

		ImGui::Separator();
		ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

		if (clear)
			Clear();

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		const char* buf = Buf.begin();
		const char* buf_end = Buf.end();

		ImGuiListClipper clipper;
		clipper.Begin(LineOffsets.Size);
		while (clipper.Step())
		{
			for (int line_no = clipper.DisplayStart; line_no < clipper.DisplayEnd; line_no++)
			{
				const char* line_start = buf + LineOffsets[line_no];
				const char* line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
				ImGui::TextUnformatted(line_start, line_end);
			}
		}
		clipper.End();

		ImGui::PopStyleVar();

		if (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
			ImGui::SetScrollHereY(1.0f);

		ImGui::EndChild();
		ImGui::End();
	}
};

struct Vector3
{
	float x, y, z;
};

struct Vector4
{
	float x, y, z, w;
};

struct Vector2
{
	float x, y;
};

struct config_container {
	bool canRender = true;
	bool canDrawESP = false;
	bool drawLine = false;
	bool drawBox = false;
	bool showPlayerInfo = false;
};

struct playerInfo {
	DWORD_PTR ptrPlayerController = 0;
	bool isSilenced = false;
	bool isInfected = false;
	int playerRoleId = 0;
	bool isPlayerRoleSet = false;
	bool inVent = false;
	bool hasBomb = false;
	bool isGhost = false;
	bool isLocal = false;
	int invisibilityDistance = 0;
	bool isSpectator = false;
	bool isRemoteSpectating = false;
	char nickname[64] = "";
	char roleName[64] = "";
	Vector3 pos;

	void reset() {
		ptrPlayerController = 0;
		isSilenced = false;
		isInfected = false;
		playerRoleId = -1;
		isPlayerRoleSet = false;
		inVent = false;
		hasBomb = false;
		isGhost = false;
		isLocal = false;
		invisibilityDistance = 0;
		isSpectator = false;
		isRemoteSpectating = false;
		nickname[0] = '\0';
		roleName[0] = '\0';
		pos = { 0.0f, 0.0f };
	}

	void updatePosition(DWORD_PTR PlayerController) {
		if (PlayerController == ptrPlayerController)
			memcpy(&pos, (int*)(PlayerController + GooseGooseDuck::PlayerController::position), 12);
	}

	void update(DWORD_PTR PlayerController) {
		if (ptrPlayerController != PlayerController) {

			ptrPlayerController = PlayerController;
		}
		wchar_t tmpNick[42] = L"";

		memcpy(tmpNick,
			(DWORD_PTR*)(*(DWORD_PTR*)(PlayerController + GooseGooseDuck::PlayerController::nickname) + 0x14),
			sizeof(wchar_t) * *(int*)(*(DWORD_PTR*)(PlayerController + GooseGooseDuck::PlayerController::nickname) + 0x10) + 1);

		WideCharToMultiByte(CP_UTF8, 0, tmpNick, -1, nickname, WideCharToMultiByte(CP_UTF8, 0, tmpNick, -1, NULL, 0, NULL, NULL), NULL, NULL);


#define GET_BOOL_VALUE(X) *(bool*)(PlayerController+X)
#define GET_INT_VALUE(X) *(int*)(PlayerController+X)

		memcpy(&pos, (int*)(PlayerController + GooseGooseDuck::PlayerController::position), 12);
		isPlayerRoleSet = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::isPlayerRoleSet);
		isLocal = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::isLocal);
		inVent = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::inVent);
		hasBomb = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::hasBomb);
		isGhost = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::isGhost);
		isSpectator = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::isSpectator);
		invisibilityDistance = GET_INT_VALUE(GooseGooseDuck::PlayerController::invisibilityDistance);
		isRemoteSpectating = GET_BOOL_VALUE(GooseGooseDuck::PlayerController::isRemoteSpectating);

		roleName[0] = '\0';
		strcat(roleName, returnRoleName(playerRoleId));

		if (isPlayerRoleSet)
			playerRoleId = *(int*)(*(DWORD_PTR*)(PlayerController + GooseGooseDuck::PlayerController::playerRoleId) + 0x10);

#undef GET_BOOL_VALUE
#undef GET_INT_VALUE
	}
};