#pragma once
#include <iostream>
#define std_size 3
using namespace std;

template <class T>
class Vector
{
private:
	int size; 
	T *mas;
public:
	Vector();
	Vector(int _size);
	Vector(const Vector<T>& v);
	~Vector();
	void SetElem(int n, T x);
	T GetElem(int n);
	T& operator[](int n);
	int GetSize();
	Vector<T> operator*(T x);
	Vector<T>& operator=(const Vector<T>& v);
	void ReSize(int n);
	T operator*(const Vector<T>& v);
	friend const Vector<T> operator*(T x, const Vector<T>& v)
	{
		Vector<T> res(v);
		for (int i = 0; i < res.size; i++)
		{
			res.mas[i] *= x;
		}
		return res;
	}
	friend const Vector<T> operator*(const Vector<T>& v, T x)
	{
		Vector<T> res(v);
		for (int i = 0; i < res.size; i++)
		{
			res.mas[i] *= x;
		}
		return res;
	}
	friend ostream& operator<<(ostream& os, const Vector<T>& v)
	{
		os << "( ";
		for (int i = 0; i < v.size; i++)
		{
			os << v.mas[i] << " ";
		}
		os << ")";
		return os;
	}
	friend istream& operator>>(istream& is, Vector<T>& v)
	{
		for (int i = 0; i < v.size; i++)
		{
			is >> v.mas[i];
		}
		return is;
	}
	Vector<T> operator+(Vector<T> v);
	Vector<T> operator-(Vector<T> v);
	Vector<T> operator++();
	Vector<T> operator++(int);
	Vector<T> operator--();
	Vector<T> operator--(int);
};

template <class T>
Vector<T>::Vector()
{
	size = std_size;
	mas = new T[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = 0;
	}
}
template <class T>
Vector<T>::Vector(int _size)
{
	if (_size < 0) throw 123;
	else {
		size = _size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
		{
			mas[i] = 0;
		}
	}
}
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size = v.size;
	mas = new T[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = v.mas[i];
	}
}
template <class T>
Vector<T>::~Vector()
{
	delete[] mas;
}
template <class T>
void Vector<T>::SetElem(int n, T x)
{
	if (n < 0 || n >= size) {
		throw 124;
	}
	else {
		mas[n] = x;
	}
	
}
template <class T>
T Vector<T>::GetElem(int n)
{
if (n < 0 || n >= size) {
		throw 124;
	}
	else {
		return mas[n];
	} 

	
}
template <class T>
T& Vector<T>::operator[](int n)
{
	return mas[n];
}
template <class T>
int Vector<T>::GetSize()
{
	
		return size;
	
	
}
template <class T>
Vector<T> Vector<T>::operator*(T x)
{
	Vector<T> res(size);
	for (int i = 0; i < size; i++)
	{
		res.mas[i] = mas[i] * x;
	}
	return res;
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this != &v)
	{
		if (size != v.size)
		{
			delete[] mas;
			size = v.size;
			mas = new T[size];
		}
		for (int i = 0; i < size; i++)
		{
			mas[i] = v.mas[i];
		}
	}
	return *this;
}
template <class T>
void Vector<T>::ReSize(int n)
{
	if (n < 0 || n >= size) {
		throw 123;
	}
	else {
		if (n != size)
		{
			T* mas2 = new T[n];
			int min;
			if (n < size)
			{
				min = n;
			}
			else
			{
				min = size;
			}
			for (int i = 0; i < min; i++)
			{
				mas2[i] = mas[i];
			}
			delete[] mas;
			mas = mas2;
			size = n;
		}
	} 

}
template <class T>
T Vector<T>::operator*(const Vector<T>& v)
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += mas[i] * v.mas[i];
	}
	return sum;
}
template <class T>
Vector<T> Vector<T>::operator+(Vector<T> v)
{
	Vector<T> res(size);
	for (int i = 0; i < size; i++)
	{
		res.mas[i] = mas[i] + v.mas[i];
	}
	return res;
}
template <class T>
Vector<T> Vector<T>::operator-(Vector<T> v)
{
	Vector<T> res(size);
	for (int i = 0; i < size; i++)
	{
		res.mas[i] = mas[i] - v.mas[i];
	}
	return res;
}
template <class T>
Vector<T> Vector<T>::operator++()
{
	for (int i = 0; i < size; i++)
	{
		mas[i]++;
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::operator++(int)
{
	Vector<T> tmp(*this);
	for (int i = 0; i < size; i++)
	{
		mas[i]++;
	}
	return tmp;
}
template <class T>
Vector<T> Vector<T>::operator--()
{
	for (int i = 0; i < size; i++)
	{
		mas[i]--;
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::operator--(int)
{
	Vector<T> tmp(*this);
	for (int i = 0; i < size; i++)
	{
		mas[i]--;
	}
	return tmp;
}
