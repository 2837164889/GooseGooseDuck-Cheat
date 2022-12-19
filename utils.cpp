#include "utils.hpp"

//https://stackoverflow.com/questions/26572459/c-get-module-base-address-for-64bit-application
DWORD_PTR GetProcessBaseAddress(DWORD processID, const wchar_t* targetModuleName)
{
	DWORD_PTR   baseAddress = 0;
	HANDLE      processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	HMODULE* moduleArray;
	LPBYTE      moduleArrayBytes;
	DWORD       bytesRequired;
	wchar_t moduleName[25] = L"";

	if (processHandle)
	{
		if (EnumProcessModules(processHandle, NULL, 0, &bytesRequired))
		{
			if (bytesRequired)
			{
				moduleArrayBytes = (LPBYTE)LocalAlloc(LPTR, bytesRequired);

				if (moduleArrayBytes)
				{
					unsigned int moduleCount;

					moduleCount = bytesRequired / sizeof(HMODULE);
					moduleArray = (HMODULE*)moduleArrayBytes;

					if (EnumProcessModules(processHandle, moduleArray, bytesRequired, &bytesRequired))
					{
						for (unsigned int i = 0; i < moduleCount; i++) {
							GetModuleBaseName(processHandle, moduleArray[i], moduleName, 24);
							if (wcscmp(moduleName, targetModuleName) == 0) baseAddress = (DWORD_PTR)moduleArray[i];
						}
					}
					LocalFree(moduleArrayBytes);
				}
			}
		}
		CloseHandle(processHandle);
	}

	return baseAddress;
}

DWORD_PTR GetGameAssemblyBase(const wchar_t* targetModuleName) {
	return GetProcessBaseAddress(GetCurrentProcessId(), targetModuleName);
}

const char* returnRoleName(int id) {
	switch (id)
	{
	case gameRoleId::None:
		return(u8"无");
		break;
	case gameRoleId::Goose:
		return(u8"鹅");
		break;
	case gameRoleId::Duck:
		return(u8"鸭子");
		break;
	case gameRoleId::Dodo:
		return(u8"渡渡鸟");
		break;
	case gameRoleId::Bounty:
		return(u8"赏金");
		break;
	case gameRoleId::Mechanic:
		return(u8"机械");
		break;
	case gameRoleId::Technician:
		return(u8"技术员");
		break;
	case gameRoleId::Medium:
		return(u8"中立");
		break;
	case gameRoleId::Vigilante:
		return(u8"义警");
		break;
	case gameRoleId::Cannibal:
		return(u8"食人族");
		break;
	case gameRoleId::Morphling:
		return(u8"变形");
		break;
	case gameRoleId::Sheriff:
		return(u8"警长");
		break;
	case gameRoleId::Silencer:
		return(u8"静音");
		break;
	case gameRoleId::Canadian:
		return(u8"加拿大人");
		break;
	case gameRoleId::LoverDuck:
		return(u8"链子鸭");
		break;
	case gameRoleId::LoverGoose:
		return(u8"链子鹅");
		break;
	case gameRoleId::Vulture:
		return(u8"秃鹫");
		break;
	case gameRoleId::Professional:
		return(u8"Professional");
		break;
	case gameRoleId::Spy:
		return(u8"间谍");
		break;
	case gameRoleId::Mimic:
		return(u8"伪装者");
		break;
	case gameRoleId::Detective:
		return(u8"侦探");
		break;
	case gameRoleId::Pigeon:
		return(u8"鸽子");
		break;
	case gameRoleId::Birdwatcher:
		return(u8"观鸟者");
		break;
	case gameRoleId::Assassin:
		return(u8"Assassin");
		break;
	case gameRoleId::Falcon:
		return(u8"猎鹰");
		break;
	case gameRoleId::Hitman:
		return(u8"杀手");
		break;
	case gameRoleId::Bodyguard:
		return(u8"保镖");
		break;
	case gameRoleId::Snitch:
		return(u8"飞贼");
		break;
	case gameRoleId::Politician:
		return(u8"政治家");
		break;
	case gameRoleId::Locksmith:
		return(u8"锁匠");
		break;
	case gameRoleId::Mortician:
		return(u8"殡仪师");
		break;
	case gameRoleId::Celebrity:
		return(u8"名人");
		break;
	case gameRoleId::Party:
		return(u8"派对");
		break;
	case gameRoleId::Demolitionist:
		return(u8"爆破手");
		break;
	case gameRoleId::DuelingDodo:
		return(u8"DuelingDodo");
		break;
	case gameRoleId::GHGoose:
		return(u8"GHGoose");
		break;
	case gameRoleId::GHDuck:
		return(u8"GHDuck");
		break;
	case gameRoleId::GHBounty:
		return(u8"GHBounty");
		break;
	case gameRoleId::HNSGoose:
		return(u8"HNSGoose");
		break;
	case gameRoleId::HNSDuck:
		return(u8"HNSDuck");
		break;
	case gameRoleId::HNSBounty:
		return(u8"HNSBounty");
		break;
	case gameRoleId::DNDDuck:
		return(u8"DNDDuck");
		break;
	case gameRoleId::DNDFalcon:
		return(u8"DNDFalcon");
		break;
	case gameRoleId::DNDVulture:
		return(u8"DNDVulture");
		break;
	case gameRoleId::DNDMorphling:
		return(u8"DNDMorphling");
		break;
	case gameRoleId::FPGoose:
		return(u8"FPGoose");
		break;
	case gameRoleId::ExploreGoose:
		return(u8"ExploreGoose");
		break;
	case gameRoleId::TTVampire:
		return(u8"TTVampire");
		break;
	case gameRoleId::TTPeasant:
		return(u8"TTPeasant");
		break;
	case gameRoleId::TTThrall:
		return(u8"TTThrall");
		break;
	case gameRoleId::Spectator:
		return(u8"Spectator");
		break;
	case gameRoleId::IdentityThief:
		return(u8"IdentityThief");
		break;
	case gameRoleId::Adventurer:
		return(u8"冒险家");
		break;
	case gameRoleId::Avenger:
		return(u8"复仇者");
		break;
	case gameRoleId::Ninja:
		return(u8"忍者");
		break;
	case gameRoleId::Undertaker:
		return(u8"捞尸人");
		break;
	case gameRoleId::Snoop:
		return(u8"探听");
		break;
	case gameRoleId::Esper:
		return(u8"Esper");
		break;
	case gameRoleId::Invisibility:
		return(u8"隐形");
		break;
	case gameRoleId::Astral:
		return(u8"灵魂者");
		break;
	case gameRoleId::Pelican:
		return(u8"鹈鹕");
		break;
	case gameRoleId::TTEThrall:
		return(u8"TTEThrall");
		break;
	case gameRoleId::TTMummy:
		return(u8"TTMummy");
		break;
	case gameRoleId::SerialKiller:
		return(u8"SerialKiller");
		break;
	case gameRoleId::Engineer:
		return(u8"工程师");
		break;



	default:
		return("None");
		break;
	}
}

bool WorldToScreen(Vector3 pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight)
{
	Vector4 clipCoords;
	clipCoords.x = pos.x * matrix[0] + pos.y * matrix[1] + pos.z * matrix[2] + matrix[3];
	clipCoords.y = pos.x * matrix[4] + pos.y * matrix[5] + pos.z * matrix[6] + matrix[7];
	clipCoords.z = pos.x * matrix[8] + pos.y * matrix[9] + pos.z * matrix[10] + matrix[11];
	clipCoords.w = pos.x * matrix[12] + pos.y * matrix[13] + pos.z * matrix[14] + matrix[15];

	if (clipCoords.w < 0.1f)
		return false;


	Vector3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;

	screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
	return true;
}