#pragma once

namespace GooseGooseDuck {

	namespace SpawnedPlayersManager {
		constexpr int fn_AddSpawnedPlayer = 0x77A430;
		constexpr int fl_spawnedPlayers = 0x18;
	}

	namespace localPlayer {
		constexpr int fn_update = 0xDF5700;
		constexpr int fl_Player = 0x18; // public PlayerController Player;
	}

	namespace unityEngineCamera {
		constexpr int fn_WorldToScreenPoint = 0x30680F0; // public Vector3 WorldToScreenPoint(Vector3 position)
		constexpr int fn_set_worldToCameraMatrix = 0x3068E20; // void set_worldToCameraMatrix(Matrix4x4 value)
	}

	namespace cinemachine {
		constexpr int fn_damp = 0x1E0C330;   //Cinemachine.Utility.Damper.Damp(Vector3 initial, Vector3 dampTime, float deltaTime)
	}

	namespace GameManager { 	// Managers.GameManagers.GameManager
		constexpr int fn_update = 0x7AB960;
		constexpr int fl_gameState = 0x18;
	}

	namespace PlayerController {
		constexpr int fn_updateRVA = 0xE12760; // AOBScan too.
		constexpr int fl_isSilenced = 0xC1; // Boolean
		constexpr int fl_isInfected = 0xC3; // Boolean
		constexpr int fl_playerRoleId = 0xE8; // pointer, [instance+playerRoleId] + 0x10, int
		constexpr int fl_isPlayerRoleSet = 0xF0; // Boolean
		constexpr int fl_inVent = 0xF1; // Boolean
		constexpr int fl_facingRight = 0x130; // Boolean, can make "Moon walk".
		constexpr int fl_hasBomb = 0x134; // Boolean
		constexpr int fl_isGhost = 0x188; // Boolean
		constexpr int fl_isLocal = 0x1C0; // Boolean
		constexpr int fl_nickname = 0x1D0; // pointer, [instance+nickname] +  0x14, length: [instance+nickname] + 0x10
		constexpr int fl_invisibilityDistance = 0x32C; // int, need this?
		constexpr int fl_isSpectator = 0x37A; // Boolean
		constexpr int fl_isRemoteSpectating = 0x37B; // Boolean
		constexpr int fl_position = 0x2C8; // Value name is randomized. x, y. Float, Float
		/*
		[Notable offsets]
		2B0, Player location, Float Float,   x, y
		2BC, using left bool. camera accel?
		Using UnityEngine-Vector3.Slerp for camera movement?
		*/
	}
}


namespace codeStage {

	namespace InjectionDetector {

	}

	namespace ObscuredCheatingDetector {

	}

	namespace SpeedHackDetector {

	}

	namespace TimeCheatingDetector {

	}

	namespace WallHackDetector {

	}

}