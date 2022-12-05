#pragma once

namespace GooseGooseDuck {
	namespace localPlayer {
		constexpr int update = 0xC0D6E0;
		constexpr int Player = 0x18; // public PlayerController Player;
	}

	namespace unityEngineCamera {
		constexpr int WorldToScreenPoint = 0x2EF1A10; // public Vector3 WorldToScreenPoint(Vector3 position)
	}

	namespace cinemachine {
		constexpr int damp = 0x1C8CE40;   //Cinemachine.Utility.Damper.Damp(Vector3 initial, Vector3 dampTime, float deltaTime)
	}

	namespace GameManager { 	// Managers.GameManagers.GameManager
		constexpr int update = 0x67E790;
		constexpr int gameState = 0x18;
	}

	namespace PlayerController {
		constexpr int flipRVA = 0x18ADB40; // Use AOBScan, outdated. NO MORE USE.
		constexpr int updateRVA = 0xC385A0; // AOBScan too.
		constexpr int isSilenced = 0xC1; // Boolean
		constexpr int isInfected = 0xC3; // Boolean
		constexpr int playerRoleId = 0xE8; // pointer, [instance+playerRoleId] + 0x10, int
		constexpr int isPlayerRoleSet = 0xF0; // Boolean
		constexpr int inVent = 0xF1; // Boolean
		constexpr int facingRight = 0x130; // Boolean, can make "Moon walk".
		constexpr int hasBomb = 0x133; // Boolean
		constexpr int isGhost = 0x180; // Boolean
		constexpr int isLocal = 0x1B0; // Boolean
		constexpr int nickname = 0x1C0; // pointer, [instance+nickname] +  0x14, length: [instance+nickname] + 0x10
		constexpr int invisibilityDistance = 0x31C; // int, need this?
		constexpr int isSpectator = 0x36A; // Boolean
		constexpr int isRemoteSpectating = 0x36B; // Boolean
		constexpr int playerNameRoleText = 0x120; // pointer 
		constexpr int m_text = 0xD8; // c# string   length: [[playerController+playerNameRoleText] + 216] + 0x10    string: [[playerController+playerNameRoleText] + 216] + 0x14
		constexpr int position = 0x2B8; // Value name is randomized. x, y. Float, Float
		constexpr int playersList = 0x10; // It's in static field.....
		/*
		[Notable offsets]
		2B0, Player location, Float Float,   x, y
		2BC, using left bool. camera accel?
		Using UnityEngine-Vector3.Slerp for camera movement?
		*/
	}
}