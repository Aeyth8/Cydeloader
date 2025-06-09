#include "pch.h"
#include <iostream>
#include "Aeyth8/Filesystem/Filesystem.h"
#include "Aeyth8/Global.h"

static void Init()
{
	AllocConsole();
	FILE* Dummy; freopen_s(&Dummy, "CONOUT$", "w", stdout); freopen_s(&Dummy, "CONIN$", "r", stdin);

	std::cout << Global::Filesystem->GetRelativePath() << "\n";
	/*

	Write your initialization logic here..

	*/
}

int __stdcall DllMain(HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hModule);

	if (ulReasonForCall != DLL_PROCESS_ATTACH) return 1;

	if (Proxy::Attach(hModule)) {
		HANDLE Thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, 0, 0, 0);
		if (Thread != nullptr) CloseHandle(Thread);
	}

	return 1;
}