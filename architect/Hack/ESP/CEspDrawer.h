#pragma once
#include <Windows.h>
#include "../../Utils/ImVec3.h"
#include "../../ASDK/R5Apex.h"
#include "../../ASDK/CBaseEntity.h"


class CEspDrawer
{
public:
	CEspDrawer();
	ImVec3    WorldToScreen(const ImVec3& pos);
	CR5Apex* m_iApexModule = NULL;
	void	DrawBox(CBaseEntity* entity, ImColor col, ImDrawList* pDrawList)
	{
        auto top    = WorldToScreen(entity->m_vecOrigin);
        auto bottom = WorldToScreen(entity->m_vecCameraOrigin + ImVec3(0, 0, 8));
        float height = fabsf(top.y - bottom.y);

        ImVec3 top_left     = bottom - ImVec3(height / 4.f, 0, 0);
        ImVec3 top_right    = bottom + ImVec3(height / 4.f, 0, 0);
        ImVec3 bottom_right = top    + ImVec3(height / 4.f, 0, 0);
        ImVec3 bottom_left  = top    - ImVec3(height / 4.f, 0, 0);

        bottom_left.x = top_left.x;
        bottom_right.x = top_right.x;

        pDrawList->AddLine(top_left, top_right,       col, 2);
        pDrawList->AddLine(top_left, bottom_left,     col, 2);
        pDrawList->AddLine(top_right, bottom_right,   col, 2);
        pDrawList->AddLine(bottom_left, bottom_right, col, 2);
	}
};