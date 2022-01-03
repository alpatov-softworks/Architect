#include "Threads.h"

Threads::Threads()
{
	this->m_hThreadsHandles.push_back(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)EntityListUpdateThread,&GEnityList::list,0, nullptr));
}
void Threads::KillAll()
{
	for (auto thread_handle : this->m_hThreadsHandles)
		TerminateThread(thread_handle, 0);
	this->m_hThreadsHandles.clear();
}
Threads::~Threads()
{
	if (!this->m_hThreadsHandles.empty())
		this->KillAll();
}
DWORD WINAPI Threads::EntityListUpdateThread(std::vector<CBaseEntity*>* pEntList)
{
	auto apexModule = (uintptr_t)GetModuleHandle(NULL);

	std::vector<CBaseEntity*> tmp_vec;
	while (true)
	{
		tmp_vec.clear();

		for (unsigned int i = 0; i < 15000; ++i)
		{
			auto ent = *(CBaseEntity**)(apexModule+ 0x241F1A8 + i * 0x30);
			// 0x15AE338 is vmt pointer of dummies
			if (!ent or *(uintptr_t*)(ent) != (uintptr_t)apexModule + 0x15AE338)
				continue;
			tmp_vec.push_back(ent);
		}
		*pEntList = tmp_vec;
		Sleep(500);
	}
}
