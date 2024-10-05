#include "Vector.h"
#include<iostream>
#include<Windows.h>
#include <initializer_list>
using namespace std;

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}
Vector::Vector(int s)
{
	size = s;
	arr = new int[size];
	for (int i = 0; i < s; i++) {
		arr[i] = i + 1;
	}
}

Vector::~Vector()
{
	if (arr != nullptr) {
		cout << "Destructor\n";
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
}
Vector::Vector(const Vector& obj)
{
	cout << "Copy constructor\n";
	this->size = obj.size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}
void Vector::InputRand()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%41 - 20; // [-20 +20]
	}
}
void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n---------------------------------------------------\n";
}

void Vector::PushBack(int a)
{
	int* temp = new int[size + 1];  // содаем новый массив (тек размер +1)

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i]; // копируем текущие значения старого массива в новый массив
	}
	temp[size] = a; // инициализация последнего элемента параметром метода

	delete[] arr; // удаление старого массива!

	arr = temp; // перенаправляем указатель в объекте на новый дин. массив
	size++;

}

int Vector::PopBack()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	int el = arr[size - 1]; // достаем последний элемент старого массива ДО удаления

	delete[] arr;
	arr = temp;
	size--;

	return el;
}
Vector& Vector::operator=(const Vector& obj)
{
	if (this == &obj) {
		return *this;  // Проверка на самоприсваивание
	}

	// Удаляем старую память, чтобы избежать утечек
	delete[] arr;

	// Копируем размер
	this->size = obj.size;

	// Выделяем новую память
	this->arr = new int[size];

	// Копируем элементы
	for (int i = 0; i < size; i++) {
		this->arr[i] = obj.arr[i];
	}

	return *this;
}

Vector Vector::operator- (int a)
{
	if (size >= 5) {
		Vector rez(size - a); // 5 - 2 = 3
		for (int i = 0; i < rez.size; i++)
		{
			rez.arr[i] = this->arr[i];
		}
		return rez;
	}
	return Vector();

}

Vector Vector::operator+(int a)
{
	Vector rez(size + a);
	for (int i = 0; i < size; i++) {
		rez.arr[i] = this->arr[i];
	}
	for (int i = size; i < size + a; i++) {
		rez.arr[i] = 0;
	}
	return rez;
}

Vector Vector::operator*(int a)
{
	return Vector();
}

Vector Vector::operator/(int a)
{
	return Vector();
}

//Vector::Vector(initializer_list<int> a)
//{
//	size = a.size();
//	arr = new int[size];
//	for (auto x = a.begin(); x != a.end(); x++) {
//		*arr = *x;
//		arr++;
//	}
//	arr -= size;
//}
