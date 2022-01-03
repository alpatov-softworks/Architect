#pragma once
class Matrix4x4
{
public:
	const float* operator[ ](int index) const
	{
		return m_pfData[index];
	}
private:
	float m_pfData[4][4];
};