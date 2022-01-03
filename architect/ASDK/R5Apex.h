#pragma once
#include "../Utils/Matrix4x4.h"
#include "../Utils/ImVec3.h"
#include "Padding.h"
#include "CBaseEntity.h"

class CR5Apex
{
public:
	union 
	{

		DEFINE_MEMBER_N(Matrix4x4, m_ViewMatrix, 0x2317100);
		DEFINE_MEMBER_N(ImVec3, m_vecLocalCameraOrigin, 0x1989DD4);
		DEFINE_MEMBER_N(const char*, m_LocalPlayerName, 0x24718BD2);
		DEFINE_MEMBER_N(uintptr_t, m_EntityList, 0x241F1A8);
	};

private:

};