#pragma once
#include "../../pch.h"

/*

Written by Aeyth8

https://github.com/Aeyth8

*/

class Proxy
{
public:

	struct ProxyStructure { void** FunctionPointer; const char* FunctionName; };
	//struct ProxyModule { const std::vector<ProxyStructure> Proxy; };

private:

	static void InitProxyPointers(const HMODULE& hModule, const std::vector<ProxyStructure>& Table);


public:

	static bool Attach(HMODULE CurrentModule);
	static void Detach(HMODULE CurrentModule);
	
	





};