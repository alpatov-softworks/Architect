#pragma once
#include <Windows.h>
#include "../../Utils/ImVec3.h"
#include "../../ASDK/R5Apex.h"

class CEspDrawer
{
public:
	CEspDrawer();
	ImVec3    WorldToScreen(const ImVec3& pos);
	CR5Apex* m_iApexModule = NULL;
};