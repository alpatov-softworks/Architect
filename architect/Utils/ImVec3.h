#pragma once
#include "../imgui/imgui.h"
#include <cmath>
#include "Matrix4x4.h"

class ImVec3 : public ImVec2
{
public:
	float z = 0;

	ImVec3(float x, float y, float z) : ImVec2(x,y)
	{
		this->z = z;
	}
	ImVec3() : ImVec2()
	{

	};
    bool operator==(const ImVec3& src) const
    {
        return (src.x == x) && (src.y == y) && (src.z == z);
    }
    float& operator[ ](int index)
    {
        return reinterpret_cast<float*>(this)[index];
    }
    bool operator!=(const ImVec3& src) const
    {
        return (src.x != x) || (src.y != y) || (src.z != z);
    }

    ImVec3& operator+=(const ImVec3& v)
    {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    ImVec3& operator-=(const ImVec3& v)
    {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    ImVec4 operator*(const Matrix4x4& matrix) const
    {
        float _x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        float _y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        float _z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        float _w = matrix[3][0] * x + matrix[3][1] * y + matrix[3][2] * z + matrix[3][3];

        return ImVec4(_x, _y, _z, _w);
    }
    ImVec3& operator*=(float fl)
    {
        x *= fl;
        y *= fl;
        z *= fl;
        return *this;
    }
    ImVec3& operator*=(const ImVec3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    
    ImVec3& operator/=(const ImVec3& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }
    ImVec3& operator+=(float fl)
    {
        x += fl;
        y += fl;
        z += fl;
        return *this;
    }
    ImVec3& operator/=(float fl)
    {
        x /= fl;
        y /= fl;
        z /= fl;
        return *this;
    }
    ImVec3& operator-=(float fl)
    {
        x -= fl;
        y -= fl;
        z -= fl;
        return *this;
    }
    float DistTo(const ImVec3& vOther) const
    {
        ImVec3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.Length();
    }
    float DistToSqr(const ImVec3& vOther) const
    {
        ImVec3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.LengthSqr();
    }
    float Dot(const ImVec3& vOther) const
    {
        return (x * vOther.x + y * vOther.y + z * vOther.z);
    }
    float Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }
    float LengthSqr(void) const
    {
        return (x * x + y * y + z * z);
    }
    float Length2D() const
    {
        return sqrt(x * x + y * y);
    }

    ImVec3& operator=(const ImVec3& vOther)
    {
        x = vOther.x; y = vOther.y; z = vOther.z;
        return *this;
    }

    ImVec3 operator-(void) const
    {
        return ImVec3(-x, -y, -z);
    }
    ImVec3 operator+(const ImVec3& v) const
    {
        return ImVec3(x + v.x, y + v.y, z + v.z);
    }
    ImVec3 operator-(const ImVec3& v) const
    {
        return ImVec3(x - v.x, y - v.y, z - v.z);
    }
    ImVec3 operator*(float fl) const
    {
        return ImVec3(x * fl, y * fl, z * fl);
    }
    ImVec3 operator*(const ImVec3& v) const
    {
        return ImVec3(x * v.x, y * v.y, z * v.z);
    }
    ImVec3 operator/(float fl) const
    {
        return ImVec3(x / fl, y / fl, z / fl);
    }
    ImVec3 operator/(const ImVec3& v) const
    {
        return ImVec3(x / v.x, y / v.y, z / v.z);
    }

    void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
    {
        x = ix; y = iy; z = iz;
    }
};
