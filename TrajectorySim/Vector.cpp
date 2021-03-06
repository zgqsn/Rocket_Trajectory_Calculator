#include "Vector.h"

template <class T, std::size_t N >
Vector<T,N>::Vector()
{
	Values = new std::array < T, N > ;
}
template <class T, std::size_t N >
const T Vector<T, N>::getValue(std::size_t pos) const
{
	return (*Values)[pos];
}
template <class T, std::size_t N >
void Vector<T,N>::setValue(std::size_t pos, const T val)
{
	(*Values)[pos] = val;
}
template <class T, std::size_t N >
Vector<T, N> &Vector<T, N>::operator=(const Vector<T, N>& right)
{
    for(int i = 0; i < N; i++)
        (*this)[i] = right[i];
	return *this;
}

template <class T, std::size_t N >
T &Vector<T, N>::operator[](const int& pos)
{
	return (*Values)[pos];
}

template <class T, std::size_t N >
T &Vector<T, N>::operator[](const int& pos)const
{
    return Values->at(pos);
}

template <class T, std::size_t N >
Vector<T, N> &Vector<T, N>::operator+=(const Vector<T, N>& right)
{
	for (int i = 0; i < N; i++)
		(*this->Values)[i] += (*right.Values)[i];
	return *this;
}
template <class T, std::size_t N >
Vector<T, N> &Vector<T, N>::operator+=(T right)
{
	for (int i = 0; i < N; i++)
		(*this->Values)[i] += right;
	return *this;
}
template <class T, std::size_t N >
Vector<T, N> &Vector<T, N>::operator*=(const Vector<T, N>& right)
{
	for (int i = 0; i < N; i++)
		(*this->Values)[i] *= (*right.Values)[i];
	return *this;
}
template <class T, std::size_t N >
Vector<T, N> &Vector<T, N>::operator*=(T right)
{
	for (int i = 0; i < N; i++)
		(*this->Values)[i] *= right;
	return *this;
}
template <class T, std::size_t N >
Vector<T, N> operator*(Vector<T, N>& left, const Vector<T, N>& right)
{
	Vector<T, N> temp;
	for (int i = 0; i < N; i++)
		temp[i] = left[i];
	return temp *= right;
}
template <class T, std::size_t N >
Vector<T, N> operator*(Vector<T, N>& left, T right)
{
	Vector<T, N> temp;
	for (int i = 0; i < N; i++)
		temp[i] = left[i];
	return temp *= right;
}
template <class T, std::size_t N >
Vector<T, N> operator+(Vector<T, N>& left, const Vector<T, N>& right)
{
	Vector<T, N> temp;
	for (int i = 0; i < N; i++)
		temp[i] = left[i];
	return temp += right;
}
template <class T, std::size_t N >
Vector<T, N> operator+(Vector<T, N>& left, T right)
{
	Vector<T, N> temp;
	for (int i = 0; i < N; i++)
		temp[i] = left[i];
	return temp += right;
}
template <class T, std::size_t N >
T operator|(Vector<T, N>& left, const Vector<T, N>& right)
{
	T result = (*left.Values)[0] * (*right.Values)[0];
	for (int i = 1; i < N; i++)
		result += ((*left.Values)[i] * (*right.Values)[i]);
	return result;
}