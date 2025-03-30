#include "Global.h"





DWORD __stdcall Global::ConstructThread(LPVOID Function, LPVOID Parameter) {
	void* Thread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Function, Parameter, 0, 0);
	if (Thread != nullptr) CloseHandle(Thread);
	return 0;
}

static std::wstring WideStringCache{L""};
std::wstring Global::StringToW(const std::string& Str){ 
	return WideStringCache.assign(Str.begin(), Str.end());
}

static std::string NarrowStringCache{""};
std::string Global::WStringToN(const std::wstring& Str) {
	return NarrowStringCache.assign(Str.begin(), Str.end());
}