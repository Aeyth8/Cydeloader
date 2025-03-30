#include "Proxy.h"

/*

Written by Aeyth8

https://github.com/Aeyth8

*/

/*
	----- Private -----
*/

void Proxy::InitProxyPointers(const HMODULE& hModule, const std::vector<ProxyStructure>& Table)
{
	for (int i{0}; i < Table.size(); ++i)
	{
		*Table[i].FunctionPointer = (void*)(GetProcAddress(hModule, Table[i].FunctionName));
		//Logger::Log << "[Proxy] - POINTERS :: " << Table[i].FunctionName << " " << std::hex << std::uppercase << Table[i].FunctionPointer << "\n";
	}
}

/*
	----- Public -----
*/


static int AttachCounter{0};
static bool IsInitialized{false};

bool Proxy::Attach(HMODULE CurrentModule)
{
	WCHAR Path[260]{0}; // Current path of this dll during runtime.

	++AttachCounter;
	if (AttachCounter == 1) /* Logger::Init()*/;

	return true;
}

void Proxy::Detach(HMODULE CurrentModule) { if (CurrentModule != nullptr) FreeLibrary(CurrentModule); }