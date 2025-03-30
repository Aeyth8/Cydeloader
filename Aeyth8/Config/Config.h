#pragma once
#include "../../pch.h"



class Config
{
public:

	// Contains the default values for a configuration.
	struct ConfigStructure { const char* Section; const char* Key; const char* Value; };

	// Construct a default configuration file, overwrites any preexisting ones.  
	static void ConstructConfig(const std::wstring& Path, const std::vector<ConfigStructure>& Configuration);


};