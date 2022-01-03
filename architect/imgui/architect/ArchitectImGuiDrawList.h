#include "../imgui.h"

class CArchitectImGuiCustomDrawList : public ImDrawList
{
public:
	void AddOutlinedText(const ImVec2& position, ImColor col, const char* text_begin, const char* text_end = NULL);

};