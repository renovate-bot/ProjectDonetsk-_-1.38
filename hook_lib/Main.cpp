#include "Main.hpp"
#include <fstream>

utils::hook::detour Check;
utils::hook::detour dtf;
utils::hook::detour dvar_registerbool;

dvar_t* Dvar_RegisterBool(const char* dvarName, bool value, int flags, const char* desc)
{
	printf("dvar: %s\n", dvarName);
	auto func = reinterpret_cast<dvar_t * (*)(const char* dvarName, bool value, int flags, const char* desc)>(0x39F4ED0_b);
	return func(dvarName, value, flags, desc);
}

dvar_t* Dvar_RegisterBool_Detour(const char* dvarName, bool value, unsigned int flags, const char* description)
{
	printf("dvar: %s : %d\n", dvarName, value);
	
	volatile static bool onceCalled = false;
	
	if (onceCalled == false)
	{
		puts("it got called & detoured...");
		onceCalled = true;

		dvar_registerbool.stub<dvar_t*>("LPSPMQSNPQ", true, flags, description);
		dvar_registerbool.stub<dvar_t*>("LRKPTLNQTT", true, flags, description);
		dvar_registerbool.stub<dvar_t*>("LTSNLQNRKO", false, flags, description);
		dvar_registerbool.stub<dvar_t*>("NOSONNPTLM", true, flags, description);
		dvar_registerbool.stub<dvar_t*>("MQSSSPSLMK", true, flags, description);
		dvar_registerbool.stub<dvar_t*>("LKSQOLNKLP", true, flags, description);
	}

	if (strcmp(dvarName, "LNLPTMKPT") == 0) {
		printf("dvar registered!\n");
		value = true;
	}
	if (strcmp(dvarName, "LNLNSSNKQ") == 0) {
		printf("dvar registered!\n");
		value = true;
	}
	if (strcmp(dvarName, "LSTQOKLTRN") == 0) {
		printf("dvar registered!\n");
		value = true;
	}
	if (strcmp(dvarName, "MPSSOTQQPM") == 0) {
		printf("dvar registered!\n");
		value = true;
	}

	//dvar_registerbool.stub<dvar_t*>("LNLPTMKPT", true, flags, description);
	//dvar_registerbool.stub<dvar_t*>("LNLNSSNKQ", true, flags, description);
	//
	//dvar_registerbool.stub<dvar_t*>("LQKTNLONLP", true, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MTSTMMKPMRM", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("LLOKQOSPPP", true, flags, description);

	//dvar_registerbool.stub<dvar_t*>("OLTKTKRKO", true, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MKPKPMNLPN", true, flags, description);

	//dvar_registerbool.stub<dvar_t*>("LSTLQTSSRM", true, flags, description);
	dvar_registerbool.stub<dvar_t*>("LKNKMMLKNR", true, flags, description);
	dvar_registerbool.stub<dvar_t*>("LOMSTMNPRR", true, flags, description);
	dvar_registerbool.stub<dvar_t*>("MPNKQNOKKS", true, flags, description);
	dvar_registerbool.stub<dvar_t*>("MSSMLKNMRT", true, flags, description);

	//////Unlocks
	////dvar_registerbool.stub<dvar_t*>("OKPRQTRPMP", false, flags, description);
	////dvar_registerbool.stub<dvar_t*>("OLKMKMTKRO", true, flags, description);
	////dvar_registerbool.stub<dvar_t*>("NSPPTONLNP", true, flags, description);
	////dvar_registerbool.stub<dvar_t*>("NLOTNSOSKK", true, flags, description);
	////dvar_registerbool.stub<dvar_t*>("MNRNRKMQKK", true, flags, description);
	////dvar_registerbool.stub<dvar_t*>("MNLPOPMMSK", true, flags, description);
	////dvar_registerbool.stub<dvar_t*>("LSPQSSPSOL", true, flags, description);

	////Test
	//dvar_registerbool.stub<dvar_t*>("MSROQTTQNS", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("OTRLKTPNR", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("NQPTLKMSNO", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("LOPKTKKSTK", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MMKQPKOOSL", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("LMTNLRSPSN", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MSMKRKOKQP", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("LKMRQOTSQS", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("OLNMMOQSRR", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("NTRSQNLOO", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("ROOPTTNMS", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("NQNLLPTLSN", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MOLLKMTMRS", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("OMOPKRQROK", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("NLNKQNROQM", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MQOPRPQLQL", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("SQPTQTLRK", false, flags, description);
	//dvar_registerbool.stub<dvar_t*>("MQONROQQSR", false, flags, description);


	dvar_t* ret = dvar_registerbool.stub<dvar_t*>(dvarName, value, flags, description);

	return ret;
}

void lua_pushboolean(uintptr_t luaState, int boolean)
{
	auto func = reinterpret_cast<void(*)(uintptr_t luaState, int boolean)>(0x6BD9C10_b);
	func(luaState, boolean);
}



uintptr_t get_bnet_class()
{
	return 0x37B22A0_b;
}

struct XUID {
	unsigned __int64 m_id;

	XUID* RandomXUID();

	bool operator !=(const XUID* xuid);
	XUID* operator =(const XUID* xuid);
	bool operator ==(const XUID* xuid);

};


unsigned int* GetRandSeed()
{
	static unsigned int seed = 0x2D4E350;
	return &seed;
}

unsigned __int64 Sys_Microseconds()
{
	auto func = reinterpret_cast<unsigned __int64(*)(void)>(0x2E67190_b);
	return func();
}

int I_irand(int min, int max)
{
	auto func = reinterpret_cast<int(*)(int min, int max)>(0x2D4E5D0_b);
	return func(min, max);
}

XUID* XUID::RandomXUID()
{
	unsigned int* RandSeed;
	unsigned int BackupRandSeed;
	this->m_id = 0;
	RandSeed = GetRandSeed();
	BackupRandSeed = *RandSeed;
	*RandSeed = Sys_Microseconds();
	this->m_id = I_irand(1, 0x7FFFFFFF);
	*RandSeed = BackupRandSeed;
	return this;
}

void LUI_OpenMenu(uintptr_t localclientnum, const char* menuName, int isPopup, int isModal, int isExclusive)
{
	auto func = reinterpret_cast<void(*)(uintptr_t localclientnum, const char* menuName, int isPopup, int isModal, int isExclusive)>(0x5622C10_b);
	printf("Menu: %s\n", menuName);
	//
	dtf.stub<void>(localclientnum, menuName, isPopup, isModal, isExclusive);

	//func(localclientnum, menuName, isPopup, isModal, isExclusive);
}

void delayedStuff()
{
	while (1)
	{
		if (GetAsyncKeyState('H') & 0x8000)
		{
			const char* menuName = "SystemLink_MainMenu";
			printf("LUI_OpenMenu(0, \"%s\", true, false, false);\n", menuName);
			LUI_OpenMenu(0, menuName, true, false, false);
			Sleep(1000);
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			const char* menuName = "SystemLink";
			printf("LUI_OpenMenu(0, \"%s\", true, false, false);\n", menuName);
			LUI_OpenMenu(0, menuName, true, false, false);
			Sleep(1000);
		}
		if (GetAsyncKeyState('B') & 0x8000)
		{
			const char* menuName = "CPMainMenu";
			printf("LUI_OpenMenu(0, \"%s\", true, false, false);\n", menuName);
			LUI_OpenMenu(0, menuName, true, false, false);
			Sleep(1000);
		}
	}
}
//


bool Live_IsUserSignedIn_Detour(int unk);

int iTick = 0;
bool bFinished;
bool btoggle;
utils::hook::detour r_endframe;
void R_EndFrame_Detour()
{

	if (!bFinished) {
		if (iTick == 500) {
			XUID xuid;
			xuid.RandomXUID();
			printf("xuid: %llu\n", xuid.m_id);

			utils::hook::set(0x8B6F750_b, 1);

			utils::hook::set<uintptr_t>(0x16AB32B8_b, 0x11CB1243B8D7C31E | xuid.m_id * xuid.m_id);

			utils::hook::set<uintptr_t>(0x16AB32E0_b, 0x11CB1243B8D7C31E | (xuid.m_id * xuid.m_id) / 6); // s_presenceData

			utils::hook::set<int>(base + 0x1673F600, 1);
	
			utils::hook::set<int>(0x8B6F480_b, 2);

			utils::hook::set<int>(0x8B6F750_b, 1);
	
			utils::hook::set<char>(*reinterpret_cast<uintptr_t*>(base + 0x15311380) + 0x28, 2);
			utils::hook::set<char>(*reinterpret_cast<uintptr_t*>(base + 0x15311388) + 0x28, 0);

			utils::hook::set(base + 0x16AB3220, 2);


			uintptr_t bnet_class = get_bnet_class();
			*(bool*)(bnet_class + 0x2D0) = true;

			*(DWORD*)(bnet_class + 0x2F4) = 0x795230F0;
			*(DWORD*)(bnet_class + 0x2FC) = 0;
			*(BYTE*)(bnet_class + 0x2F8) = 31;



			printf("LOADED!\n");
			bFinished = true;

		}
		else {
			iTick += 1;
		}
	}

	r_endframe.stub<void>();
}


__int64 Live_IsUserSignedIn_Detour(__int64 unk)
{
	return 1;
}

int Live_IsUserSignedInToDemonware_Detour(int unk)
{
	return 1;
}

int dwGetLogOnStatus_Detour(int unk)
{
	return 2;
}

int LiveStorage_GetActiveStatsSource_Detour()
{
	return 1;
}

int LUI_CoD_LuaCall_IsUserSignedInToLive_Detour(uintptr_t luaState) // 0x6294930_b
{
	lua_pushboolean(luaState, 1);
	return 1;
}

int LUI_CoD_LuaCall_IsUserSignedInToDemonware_Detour(uintptr_t luaState) // 0x62949F0_b
{
	lua_pushboolean(luaState, 1);
	return 1;
}

bool IsUserSignedInToBnet_Detour(int controllerIndex, int* onlinePlayFailReason) // guessed name
{
	*onlinePlayFailReason = 0; // OPFR_NONE
	return true;
}

bool GamerProfile_IsProfileLoggedIn_Detour(int unk)
{
	return true;
}

const char* username_Detour()
{
	return "Sku-111";
}

const char* SEH_StringEd_GetString_Detour(const char* str)
{
	return str;
}

bool Content_DoWeHaveContentPack_Detour(int unk1)
{
	return true;
}

void entry_point()
{


	XUID xuid;
	xuid.RandomXUID();

	printf("%i\n", xuid.m_id);

	//BECAUSE OF ARXAN IF YOU LOAD IT TOO EARLY IT WILL CLOSE
	Sleep(5000);
	// NEED TO REVERSE THIS TOO
	//utils::hook::jump(0x425B3C0_b, GamerProfile_IsProfileLoggedIn_Detour);

	r_endframe.create(0x5098750_b, R_EndFrame_Detour);
	dtf.create(0x5622C10_b, LUI_OpenMenu);

	dvar_registerbool.create(0x2D5F460_b, Dvar_RegisterBool_Detour);

	utils::hook::nop(0x4F2345E_b, 6);

	puts(__FUNCTION__ " done.");
}

extern "C" __declspec(dllexport) int DiscordCreate()
{
	CreateThread(0, 0xA0, (LPTHREAD_START_ROUTINE)entry_point, 0, 0, 0);

	puts(__FUNCTION__ " done.");
	return 1;
}

BOOL IsDebuggerPresent_Detour()
{
	puts("IsDebuggerPresent()...");
	return FALSE;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD Reason, LPVOID lpVoid)
{
	g_Addrs.ModuleBase = (uintptr_t)(GetModuleHandleA(NULL));
	if (Reason == DLL_PROCESS_ATTACH)
	{
		HANDLE hCmd = createConsole();
		if (hCmd == NULL)
		{
			MessageBoxA(NULL, "Couldn't create console.", "", MB_ICONERROR | MB_OK | MB_DEFBUTTON1);
		}

		printf("Base Address: 0x%p\n", g_Addrs.ModuleBase);
	}

	return TRUE;
}

std::pair<void**, void*> patch_import(const std::string& lib, const std::string& func, void* function)
{
	static const utils::nt::library game{};

	const auto game_entry = game.get_iat_entry(lib, func);
	if (!game_entry)
	{
		throw std::runtime_error("Import '" + func + "' not found!");
	}

	const auto original_import = game_entry;
	utils::hook::set(game_entry, function);
	return { game_entry, original_import };
}

uintptr_t find_pattern(const char* module_name, const char* pattern) {
	const auto get_module_size = [=](uintptr_t module_base)
		{
			return reinterpret_cast<PIMAGE_NT_HEADERS>(module_base + reinterpret_cast<PIMAGE_DOS_HEADER>(module_base)->e_lfanew)->OptionalHeader.SizeOfImage;
		};
	const auto module_start = (uintptr_t)GetModuleHandle(module_name);
	if (module_start != 0ULL)
	{
		const auto module_end = module_start + get_module_size(module_start);

		const char* pattern_current = pattern;
		uintptr_t current_match = NULL;

		MEMORY_BASIC_INFORMATION64 page_information = {};
		for (auto current_page = reinterpret_cast<unsigned char*>(module_start); current_page < reinterpret_cast<unsigned char*>(module_end); current_page = reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize))
		{
			VirtualQuery(reinterpret_cast<LPCVOID>(current_page), reinterpret_cast<PMEMORY_BASIC_INFORMATION>(&page_information), sizeof(MEMORY_BASIC_INFORMATION));
			if (page_information.Protect == PAGE_NOACCESS)
				continue;

			if (page_information.State != MEM_COMMIT)
				continue;

			if (page_information.Protect & PAGE_GUARD)
				continue;

			for (auto current_address = reinterpret_cast<unsigned char*>(page_information.BaseAddress); current_address < reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize - 0x8); current_address++)
			{
				if (*current_address != GET_BYTE(pattern_current) && *pattern_current != '\?') {
					current_match = 0ULL;
					pattern_current = pattern;
					continue;
				}

				if (!current_match)
					current_match = reinterpret_cast<uintptr_t>(current_address);

				pattern_current += 3;
				if (pattern_current[-1] == NULL)
					return current_match;
			}
		}
	}

	return 0ULL;
}

uintptr_t find_pattern(uintptr_t start, const char* module_name, const char* pattern) {
	const auto get_module_size = [=](uintptr_t module_base)
		{
			return reinterpret_cast<PIMAGE_NT_HEADERS>(module_base + reinterpret_cast<PIMAGE_DOS_HEADER>(module_base)->e_lfanew)->OptionalHeader.SizeOfImage;
		};
	const auto module_start = start;
	if (module_start != 0ULL)
	{
		const auto module_end = module_start + get_module_size(module_start);

		const char* pattern_current = pattern;
		uintptr_t current_match = NULL;

		MEMORY_BASIC_INFORMATION64 page_information = {};
		for (auto current_page = reinterpret_cast<unsigned char*>(module_start); current_page < reinterpret_cast<unsigned char*>(module_end); current_page = reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize))
		{
			VirtualQuery(reinterpret_cast<LPCVOID>(current_page), reinterpret_cast<PMEMORY_BASIC_INFORMATION>(&page_information), sizeof(MEMORY_BASIC_INFORMATION));
			if (page_information.Protect == PAGE_NOACCESS)
				continue;

			if (page_information.State != MEM_COMMIT)
				continue;

			if (page_information.Protect & PAGE_GUARD)
				continue;

			for (auto current_address = reinterpret_cast<unsigned char*>(page_information.BaseAddress); current_address < reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize - 0x8); current_address++)
			{
				if (*current_address != GET_BYTE(pattern_current) && *pattern_current != '\?') {
					current_match = 0ULL;
					pattern_current = pattern;
					continue;
				}

				if (!current_match)
					current_match = reinterpret_cast<uintptr_t>(current_address);

				pattern_current += 3;
				if (pattern_current[-1] == NULL)
					return current_match;
			}
		}
	}

	return 0ULL;
}

size_t operator"" _b(const size_t val)
{
	return base + val;
}

size_t reverse_b(const size_t val)
{
	return val - base;
}

//size_t reverse_b(const void* val)
//{
//	return reverse_b(reinterpret_cast<size_t>(val));
//}

size_t operator"" _g(const size_t val)
{
	return base + (val - 0x140000000);
}

size_t reverse_g(const size_t val)
{
	return (val - base) + 0x140000000;
}

size_t reverse_g(const void* val)
{
	return reverse_g(reinterpret_cast<size_t>(val));
}

HANDLE createConsole()
{
	AllocConsole();

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	auto a = freopen("CONOUT$", "w", stdout);
	auto b = freopen("CONOUT$", "w", stderr);
	auto c = freopen("CONIN$", "r", stdin);
	if (a == NULL || b == NULL || c == NULL)
	{
		return NULL;
	}

	SetConsoleTitleA("MW19 - 1.44");

	DWORD consoleMode;
	GetConsoleMode(consoleHandle, &consoleMode);
	SetConsoleMode(consoleHandle, consoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	return consoleHandle;
}

void printSig(std::string name, void* address, size_t len)
{
	std::cout << name << " '";
	unsigned char* ptr = static_cast<unsigned char*>(address);
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(ptr[i]);
		if (i < len - 1)
			std::cout << ' ';
	}
	std::cout << "'" << std::dec << std::endl;
}

bool isSubStr(std::string str, std::string subStr)
{
	size_t pos = str.find(subStr);
	if (pos != std::string::npos)
	{
		return true;
	}
	return false;
}

float strToFloat(const std::string& str)
{
	float num = 0.0f;
	float fraction = 0.1f;
	bool isNegative = false;

	size_t i = 0;
	if (str[i] == '-')
	{
		isNegative = true;
		i++;
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10.0f + static_cast<float>(str[i] - '0');
		}
		else if (str[i] == '.')
		{
			i++;
			break;
		}
		else
		{
			break;
		}
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num += (str[i] - '0') * fraction;
			fraction *= 0.1f;
		}
		else
		{
			break;
		}
	}

	if (isNegative)
	{
		num = -num;
	}

	return num;
}