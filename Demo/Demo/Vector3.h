#ifndef __VECTOR3_H_INCLUDED__
#define __VECTOR3_H_INCLUDED__

#include <math.h>

class Vector3
{
public:
	float x, y, z;

	//�޲ι���
	Vector3() {}
	//���ƹ������
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	//����������
	Vector3(float nx, float ny, float nz) :x(nx), y(ny), z(nz) {}

	//������
	void zero() { x = y = z = 0.0f; }

	//������
	Vector3 operator -() const { return Vector3(-x, -y, -z); }

	//���Ա���,����һ���µ�����
	Vector3 operator *(float a) const
	{
		return Vector3(x * a, y * a, z * a);
	}

	//���Ա���,����һ���µ�����
	Vector3 operator /(float a) const
	{
		float oneOverA = 1.0f / a;//������г����ٶȱȳ˷��ٶ���
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}

	//���Ա���
	Vector3 operator *=(float a)
	{
		x *= a; y *= a; z *= a;
		return *this;
	}

	//���Ա���
	Vector3 operator /=(float a)
	{
		float oneOverA = 1.0f / a;//������г����ٶȱȳ˷��ٶ���
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	//����һ���������������µ�����
	Vector3 operator +(const Vector3& a) const
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	//��ȥһ���������������µ�����
	Vector3 operator -(const Vector3& a) const
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	//����һ������
	Vector3 operator +=(const Vector3& a)
	{
		x += a.x; y += a.y; z += a.z;
		return *this;
	}

	//��ȥһ������
	Vector3 operator -=(const Vector3& a)
	{
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}

	//��һ������λ��
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

	//������ˣ������
	float operator *(const Vector3& a) const
	{
		return x * a.x + y * a.y + z * a.z;
	}

};

//����������ģ
inline float vectorMag(const Vector3& a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

//������������
inline Vector3 operator *(float k, const Vector3& v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}

//��������֮��ľ���
inline float distance(const Vector3& a, const Vector3& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrt(dx * dx + dy * dy + dz * dz);
}

//���������н�(������)
inline double arc(const Vector3& a, const Vector3& b)
{
	//���ؼн�
	return acos((a * b) / (vectorMag(a) * vectorMag(b)));
}

//�����������
inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}
#endif