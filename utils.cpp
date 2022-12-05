#include "utils.hpp"
#include "GameData.hpp"

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
		return(u8"鹅：只是一只普通的鹅。没有特殊能力");
		break;
	case gameRoleId::Duck:
		return(u8"鸭子（邪恶）角色");
		break;
	case gameRoleId::Dodo:
		return(u8"渡渡鸟：被投票出局获胜");
		break;
	case gameRoleId::Bounty:
		return(u8"赏金：完成所有任务以最大化赏金并生存。如果你死了，杀手会偷走你的赏金。");
		break;
	case gameRoleId::Mechanic:
		return(u8"机械：唯一会使用通风口的鹅。离开通风口时有一个冷却时间。");
		break;
	case gameRoleId::Technician:
		return(u8"技术员：可以大致估计从哪里调用破坏活动。");
		break;
	case gameRoleId::Medium:
		return(u8"中立：能看到鬼的数量");
		break;
	case gameRoleId::Vigilante:
		return(u8"义警：杀死一名玩家而不承担后果（如果你被投票出局，你就留在游戏中）");
		break;
	case gameRoleId::Cannibal:
		return(u8"食人族：可以吃尸体，消除所有谋杀证据");
		break;
	case gameRoleId::Morphling:
		return(u8"变形：可以变身为不同的玩家");
		break;
	case gameRoleId::Sheriff:
		return(u8"警长：可以杀死除鹅以外的所有人");
		break;
	case gameRoleId::Silencer:
		return(u8"静音：您可以在会议期间将玩家静音");
		break;
	case gameRoleId::Canadian:
		return(u8"加拿大人：杀手会自动自我报告你的身体");
		break;
	case gameRoleId::LoverDuck:
		return(u8"链子鸭：和爱人一起活下去。如果一个人死了，另一个人也死了");
		break;
	case gameRoleId::LoverGoose:
		return(u8"链子鹅：和爱人一起活下去。如果一个人死了，另一个人也死了");
		break;
	case gameRoleId::Vulture:
		return(u8"秃鹫：吃尸体取胜");
		break;
	case gameRoleId::Professional:
		return(u8"Professional");
		break;
	case gameRoleId::Spy:
		return(u8"间谍：成为唯一投票的人向您揭示他们的角色");
		break;
	case gameRoleId::Mimic:
		return(u8"伪装者：鸭子认为你也是鸭子。");
		break;
	case gameRoleId::Detective:
		return(u8"侦探：每回合一次，侦探可以调查一名玩家，看看他们是否在该回合中杀死了任何人。");
		break;
	case gameRoleId::Pigeon:
		return(u8"鸽子：感染所有人，在一轮比赛中获胜");
		break;
	case gameRoleId::Birdwatcher:
		return(u8"观鸟者：您可以透过视野有限的墙壁看到");
		break;
	case gameRoleId::Assassin:
		return(u8"Assassin");
		break;
	case gameRoleId::Falcon:
		return(u8"猎鹰：杀光所有人，只能跳过");
		break;
	case gameRoleId::Hitman:
		return(u8"杀手：杀人换取奖励");
		break;
	case gameRoleId::Bodyguard:
		return(u8"保镖：保护某人以获得奖金");
		break;
	case gameRoleId::Snitch:
		return(u8"飞贼：如果飞贼是唯一投票给某人的玩家，可以监禁玩家吗");
		break;
	case gameRoleId::Politician:
		return(u8"政治家：你在投票中获胜，不能被送进监狱");
		break;
	case gameRoleId::Locksmith:
		return(u8"锁匠：你可以打开监狱的门");
		break;
	case gameRoleId::Mortician:
		return(u8"殡仪师：检查尸体以发现死者的角色。下一次会议以及之后的每次会议，您检查的死去玩家的角色将在其名字旁边显示其角色");
		break;
	case gameRoleId::Celebrity:
		return(u8"名人：死后每个人都会得到警觉");
		break;
	case gameRoleId::Party:
		return(u8"派对：在会议期间给别人一个高亢的声音");
		break;
	case gameRoleId::Demolitionist:
		return(u8"爆破手：在玩家身上放置炸弹");
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
		return(u8"冒险家：你不能为了绘制危险而死");
		break;
	case gameRoleId::Avenger:
		return(u8"复仇者：如果你目睹了谋杀，你可以暂时杀人");
		break;
	case gameRoleId::Ninja:
		return(u8"忍者：使用三杀冷却时间，您可以一次杀死范围内2人");
		break;
	case gameRoleId::Undertaker:
		return(u8"捞尸人：拖走尸体");
		break;
	case gameRoleId::Snoop:
		return(u8"探听：可以使用野鸭庄园的窥探位置。具有使用窥探位置的冷却时间。您不能立即在壁橱之间旅行。（那会很奇怪）");
		break;
	case gameRoleId::Esper:
		return(u8"Esper");
		break;
	case gameRoleId::Invisibility:
		return(u8"隐形：暂时不可见");
		break;
	case gameRoleId::Astral:
		return(u8"灵魂者：让你的精神穿过墙壁");
		break;
	case gameRoleId::Pelican:
		return(u8"鹈鹕：吞下玩家。作为最后的幸存者获胜。");
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
		return(u8"工程师：窥探者、技术员和机械师的组合");
		break;

	default:
		return(u8"无");
		break;
	}

	/*

None,
Goose,
Duck,
Dodo,
Bounty,
Mechanic,
Technician,
Medium,
Vigilante,
Cannibal,
Morphling,
Sheriff,
Silencer,
Canadian,
LoverDuck,
LoverGoose,
Vulture,
Professional,
Spy,
Mimic,
Detective,
Pigeon,
Birdwatcher,
Assassin,
Falcon,
Hitman,
Bodyguard,
Snitch,
Politician,
Locksmith,
Mortician,
Celebrity,
Party,
Demolitionist,
DuelingDodo,
GHGoose,
GHDuck,
GHBounty,
HNSGoose,
HNSDuck,
HNSBounty,
DNDDuck,
DNDFalcon,
DNDVulture,
DNDMorphling,
FPGoose,
ExploreGoose,
TTVampire,
TTPeasant,
TTThrall,
Spectator,
IdentityThief,
Adventurer,
Avenger,
Ninja,
Undertaker,
Snoop,
Esper,
Invisibility,
Astral,
Pelican,
TTEThrall,
TTMummy
	*/
}
