#pragma once
#include "Padding.h"
#include "../Utils/ImVec3.h"

class CLocalPlayer
{
public:
	union
	{
		DEFINE_MEMBER_N(ImVec3, m_vecCameraOrigin, 0x1b68);
		DEFINE_MEMBER_N(ImVec3, m_vecViewAngles,   0x2188);
	};
	void AimAt(const ImVec3& targetPos)
	{
		ImVec3 outViewAgnles;
		outViewAgnles.x = -asinf((targetPos.z - m_vecCameraOrigin.z) / m_vecCameraOrigin.DistTo(targetPos)) * (180 / 3.1415926f);
		outViewAgnles.y = atan2f(targetPos.y - m_vecCameraOrigin.y, targetPos.x - m_vecCameraOrigin.x) * (180 / 3.1415926f);

		if (abs(outViewAgnles.x) <= 89.f and abs(outViewAgnles.y) <= 180)
		{
			m_vecViewAngles = outViewAgnles;
		}

	}
};