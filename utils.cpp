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
		return(u8"��");
		break;
	case gameRoleId::Goose:
		return(u8"�죺ֻ��һֻ��ͨ�Ķ졣û����������");
		break;
	case gameRoleId::Duck:
		return(u8"Ѽ�ӣ�а�񣩽�ɫ");
		break;
	case gameRoleId::Dodo:
		return(u8"�ɶ��񣺱�ͶƱ���ֻ�ʤ");
		break;
	case gameRoleId::Bounty:
		return(u8"�ͽ������������������ͽ����档��������ˣ�ɱ�ֻ�͵������ͽ�");
		break;
	case gameRoleId::Mechanic:
		return(u8"��е��Ψһ��ʹ��ͨ��ڵĶ졣�뿪ͨ���ʱ��һ����ȴʱ�䡣");
		break;
	case gameRoleId::Technician:
		return(u8"����Ա�����Դ��¹��ƴ���������ƻ����");
		break;
	case gameRoleId::Medium:
		return(u8"�������ܿ����������");
		break;
	case gameRoleId::Vigilante:
		return(u8"�徯��ɱ��һ����Ҷ����е����������㱻ͶƱ���֣����������Ϸ�У�");
		break;
	case gameRoleId::Cannibal:
		return(u8"ʳ���壺���Գ�ʬ�壬��������ıɱ֤��");
		break;
	case gameRoleId::Morphling:
		return(u8"���Σ����Ա���Ϊ��ͬ�����");
		break;
	case gameRoleId::Sheriff:
		return(u8"����������ɱ�����������������");
		break;
	case gameRoleId::Silencer:
		return(u8"�������������ڻ����ڼ佫��Ҿ���");
		break;
	case gameRoleId::Canadian:
		return(u8"���ô��ˣ�ɱ�ֻ��Զ����ұ����������");
		break;
	case gameRoleId::LoverDuck:
		return(u8"����Ѽ���Ͱ���һ�����ȥ�����һ�������ˣ���һ����Ҳ����");
		break;
	case gameRoleId::LoverGoose:
		return(u8"���Ӷ죺�Ͱ���һ�����ȥ�����һ�������ˣ���һ����Ҳ����");
		break;
	case gameRoleId::Vulture:
		return(u8"ͺ�գ���ʬ��ȡʤ");
		break;
	case gameRoleId::Professional:
		return(u8"Professional");
		break;
	case gameRoleId::Spy:
		return(u8"�������ΪΨһͶƱ����������ʾ���ǵĽ�ɫ");
		break;
	case gameRoleId::Mimic:
		return(u8"αװ�ߣ�Ѽ����Ϊ��Ҳ��Ѽ�ӡ�");
		break;
	case gameRoleId::Detective:
		return(u8"��̽��ÿ�غ�һ�Σ���̽���Ե���һ����ң����������Ƿ��ڸûغ���ɱ�����κ��ˡ�");
		break;
	case gameRoleId::Pigeon:
		return(u8"���ӣ���Ⱦ�����ˣ���һ�ֱ����л�ʤ");
		break;
	case gameRoleId::Birdwatcher:
		return(u8"�����ߣ�������͸����Ұ���޵�ǽ�ڿ���");
		break;
	case gameRoleId::Assassin:
		return(u8"Assassin");
		break;
	case gameRoleId::Falcon:
		return(u8"��ӥ��ɱ�������ˣ�ֻ������");
		break;
	case gameRoleId::Hitman:
		return(u8"ɱ�֣�ɱ�˻�ȡ����");
		break;
	case gameRoleId::Bodyguard:
		return(u8"���ڣ�����ĳ���Ի�ý���");
		break;
	case gameRoleId::Snitch:
		return(u8"���������������ΨһͶƱ��ĳ�˵���ң����Լ�������");
		break;
	case gameRoleId::Politician:
		return(u8"���μң�����ͶƱ�л�ʤ�����ܱ��ͽ�����");
		break;
	case gameRoleId::Locksmith:
		return(u8"����������Դ򿪼�������");
		break;
	case gameRoleId::Mortician:
		return(u8"����ʦ�����ʬ���Է������ߵĽ�ɫ����һ�λ����Լ�֮���ÿ�λ��飬��������ȥ��ҵĽ�ɫ�����������Ա���ʾ���ɫ");
		break;
	case gameRoleId::Celebrity:
		return(u8"���ˣ�����ÿ���˶���õ�����");
		break;
	case gameRoleId::Party:
		return(u8"�ɶԣ��ڻ����ڼ������һ���߿�������");
		break;
	case gameRoleId::Demolitionist:
		return(u8"�����֣���������Ϸ���ը��");
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
		return(u8"ð�ռң��㲻��Ϊ�˻���Σ�ն���");
		break;
	case gameRoleId::Avenger:
		return(u8"�����ߣ������Ŀ����ıɱ���������ʱɱ��");
		break;
	case gameRoleId::Ninja:
		return(u8"���ߣ�ʹ����ɱ��ȴʱ�䣬������һ��ɱ����Χ��2��");
		break;
	case gameRoleId::Undertaker:
		return(u8"��ʬ�ˣ�����ʬ��");
		break;
	case gameRoleId::Snoop:
		return(u8"̽��������ʹ��ҰѼׯ԰�Ŀ�̽λ�á�����ʹ�ÿ�̽λ�õ���ȴʱ�䡣�����������ڱڳ�֮�����С����ǻ����֣�");
		break;
	case gameRoleId::Esper:
		return(u8"Esper");
		break;
	case gameRoleId::Invisibility:
		return(u8"���Σ���ʱ���ɼ�");
		break;
	case gameRoleId::Astral:
		return(u8"����ߣ�����ľ��񴩹�ǽ��");
		break;
	case gameRoleId::Pelican:
		return(u8"���ɣ�������ҡ���Ϊ�����Ҵ��߻�ʤ��");
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
		return(u8"����ʦ����̽�ߡ�����Ա�ͻ�еʦ�����");
		break;

	default:
		return(u8"��");
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
