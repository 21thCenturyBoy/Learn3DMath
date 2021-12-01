#ifndef __VECTOR3_H_INCLUDED__
#define __VECTOR3_H_INCLUDED__

#include <math.h>

class Vector3
{
public:
	float x, y, z;

	//无参构造
	Vector3() {}
	//复制构造参数
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	//带参数构造
	Vector3(float nx, float ny, float nz) :x(nx), y(ny), z(nz) {}

	//零向量
	void zero() { x = y = z = 0.0f; }

	//负向量
	Vector3 operator -() const { return Vector3(-x, -y, -z); }

	//乘以标量,返回一个新的向量
	Vector3 operator *(float a) const
	{
		return Vector3(x * a, y * a, z * a);
	}

	//除以标量,返回一个新的向量
	Vector3 operator /(float a) const
	{
		float oneOverA = 1.0f / a;//计算机中除法速度比乘法速度慢
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}

	//乘以标量
	Vector3 operator *=(float a)
	{
		x *= a; y *= a; z *= a;
		return *this;
	}

	//除以标量
	Vector3 operator /=(float a)
	{
		float oneOverA = 1.0f / a;//计算机中除法速度比乘法速度慢
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	//加上一个向量，并返回新的向量
	Vector3 operator +(const Vector3& a) const
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	//减去一个向量，并返回新的向量
	Vector3 operator -(const Vector3& a) const
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	//加上一个向量
	Vector3 operator +=(const Vector3& a)
	{
		x += a.x; y += a.y; z += a.z;
		return *this;
	}

	//减去一个向量
	Vector3 operator -=(const Vector3& a)
	{
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}

	//归一化，单位化
	void normalize()
	{
		float magSq = x * x + y * y + z * z;
		if (magSq > 0.0f)
		{
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	//向量点乘（点积）
	float operator *(const Vector3& a) const
	{
		return x * a.x + y * a.y + z * a.z;
	}

};

//返回向量的模
inline float vectorMag(const Vector3& a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

//标量乘以向量
inline Vector3 operator *(float k, const Vector3& v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}

//返回两点之间的距离
inline float distance(const Vector3& a, const Vector3& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrt(dx * dx + dy * dy + dz * dz);
}

//返回向量夹角(弧度制)
inline double arc(const Vector3& a, const Vector3& b)
{
	//返回夹角
	return acos((a * b) / (vectorMag(a) * vectorMag(b)));
}

//返回向量叉乘
inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}
#endif