#pragma once
#include "../../pch.h"


class Global
{
public:

	static DWORD __stdcall ConstructThread(LPVOID Function, LPVOID Parameter = 0);
	static std::wstring StringToW(const std::string& Str);
	static std::string WStringToN(const std::wstring& Str);






};