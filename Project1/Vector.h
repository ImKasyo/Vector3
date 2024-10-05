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
	void InputRand(); // инициализация случ числами
	void Print();// вывод на консоль

	void PushBack(int a);
	int PopBack();

	Vector& operator=(const Vector& obj);

	/// перегрузки операции
	Vector operator-(int a);
	Vector operator+(int a);
	Vector operator*(int a);
	Vector operator/(int a);

	/*Vector(initializer_list <int> a);*/
};
