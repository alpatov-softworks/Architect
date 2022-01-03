#include "CEspDrawer.h"

CEspDrawer::CEspDrawer()
{
	m_iApexModule = (CR5Apex*)GetModuleHandle("r5apex.exe");
}

ImVec3 CEspDrawer::WorldToScreen(const ImVec3& pos)
{
	auto window_size = ImVec2(1920, 1080);

    ImVec4 ndc = pos * m_iApexModule->m_ViewMatrix;

    float x = (window_size.x / 2 * (ndc.x / ndc.w)) + ((ndc.x / ndc.w) + window_size.x / 2);

    float y = -(window_size.y / 2 * (ndc.y / ndc.w)) + ((ndc.y / ndc.w) + window_size.y / 2);

    return ImVec3(x, y, ndc.w);
}