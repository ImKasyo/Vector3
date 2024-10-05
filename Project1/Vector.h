#pragma once
class Vector
{
	int* arr;
	int size;
public:
	Vector();
	~Vector();
	Vector(const Vector & obj);

	Vector(int s);
	void InputRand(); // ������������� ���� �������
	void Print();// ����� �� �������

	void PushBack(int a);
	int PopBack();

	Vector& operator=(const Vector& obj);

	/// ���������� ��������
	Vector operator-(int a);
	Vector operator+(int a);
	Vector operator*(int a);
	Vector operator/(int a);

	/*Vector(initializer_list <int> a);*/
};
