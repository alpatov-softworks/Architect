#pragma once
#include <vector>
#include "../ASDK/CBaseEntity.h"
#include "../Settings/Settings.h"

namespace GlobalVars
{
	inline SAllSettings settings;
	inline std::vector<CBaseEntity*> entityList;
	inline ImVec3* pLocalViewAngles;
}