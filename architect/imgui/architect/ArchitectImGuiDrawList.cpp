#include "ArchitectImGuiDrawList.h"

void CArchitectImGuiCustomDrawList::AddOutlinedText(const ImVec2& position, ImColor col, const char* text_begin, const char* text_end)
{
    ImVec2 tempPosition;

    tempPosition.x = position.x + 1;
    tempPosition.y = position.y + 1;
    AddText(tempPosition, ImColor(0, 0, 0), text_begin, text_end);

    tempPosition.x = position.x - 1;
    tempPosition.y = position.y - 1;
    AddText(tempPosition, ImColor(0, 0, 0), text_begin, text_end);

    tempPosition.x = position.x + 1;
    tempPosition.y = position.y - 1;
    AddText(tempPosition, ImColor(0, 0, 0), text_begin, text_end);

    tempPosition.x = position.x - 1;
    tempPosition.y = position.y + 1;
    AddText(tempPosition, ImColor(0, 0, 0), text_begin, text_end);

    tempPosition.x = position.x;
    tempPosition.y = position.y + 1;
    AddText(tempPosition, ImColor(0, 0, 0), text_begin, text_end);

    tempPosition.x = position.x;
    tempPosition.y = position.y - 1;
    AddText(tempPosition, ImColor(0, 0, 0), text_begin, text_end);

    AddText(position, col, text_begin, text_end);
}