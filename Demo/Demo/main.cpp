#include <iostream>
#include "Vector3.h"

using namespace std;

void print_v(Vector3 v)
{
	cout << "[ " << v.x << ", " << v.y << ", " << v.z << " ]" << endl;
}

int main()
{
	cout << "hello vector" << endl;

	Vector3 v1(10, 20, 30);
	print_v(v1);

	Vector3 v2(v1);
	print_v(v2);

	Vector3 v3 = -v1;
	print_v(v3);

	v2.zero();
	print_v(v2);

	Vector3 v4(5, -4, 7);
	float r = vectorMag(v4);
	cout << r << endl;

	Vector3 v5(3, -2, 7);
	Vector3 v6(0, 4, -1);
	cout << arc(v5, v6) * 180 / 3.14149 << endl;

	Vector3 v7(1, 3, 4);
	Vector3 v8(2, -5, 8);
	Vector3 cp = crossProduct(v7, v8);

	print_v(cp);

	system("pause");
	return 0;
}