#pragma once
#include "Padding.h"
#include <Windows.h>
#include "../Utils/ImVec3.h"


class CBaseEntity
{
public:
	union
	{
		DEFINE_MEMBER_N(ImVec3, m_vecOrigin, 0x554);
		DEFINE_MEMBER_N(int, m_iHealth, 0x48C);
		DEFINE_MEMBER_N(ImVec3, m_vecCameraOrigin, 0x665C);
	};

private:

};