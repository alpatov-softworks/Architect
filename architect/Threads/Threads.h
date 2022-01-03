#pragma once
#include <Windows.h>
#include <vector>
#include "../ASDK/CBaseEntity.h"
#include "../ASDK/R5Apex.h"
#include "../Globals/EntityList.h"

class Threads
{
public:
	Threads();
	void KillAll();
	~Threads();
private:
	std::vector<HANDLE> m_hThreadsHandles;

	static DWORD WINAPI EntityListUpdateThread(std::vector<CBaseEntity*>* pEntList);
};