/*!
@file
@brief Файл с описанием методов класса Complex
*/

#include <iostream>
#include <cmath>

#include "mycomplex.h"

using namespace std;

/*!
@brief Конутруктор класса
@param aRe Действительная составляющая
@param aIm Мнимая составляющая
*/

Complex::Complex(double aRe, double aIm) {
  Re = aRe;
  Im = aIm;
}
/*!
@brief Конструктор класса
@param o Комплексное число
*/
Complex::Complex(const Complex& o) {
  Re = o.Re;
  Im = o.Im;
}
/*!
@brief Деструктор класса
*/
Complex::~Complex() {
  Re = 0.0;
  Im = 0.0;
}

void Complex::Set(double aRe, double aIm) {
  Re = aRe;
  Im = aIm;
}
/*!
@brief Возвращает модуль комплексного числа
@return Модуль комплексного числа
*/
Complex::operator double()
{
    return abs();
}
/*!
    @brief Возвращает модуль выражения комплексного числа
    @return Модуль выражения комплексного числа
*/
double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}
/*!
    @brief Возвращает результат сложения комплексного числа
    @return Результат сложения комплексного числа
*/
Complex Complex::operator+(const Complex& o) {
  Complex r;
  r.Re = Re + o.Re;
  r.Im = Im + o.Im;
  return r;
}
/*!
    @brief Возвращает результат вычитания комплексного числа
    @return Результат вычитания комплексного числа
*/
Complex Complex::operator-(const Complex& o) {
  Complex r;
  r.Re = Re - o.Re;
  r.Im = Im - o.Im;
  return r;
}
/*!
    @brief Возвращает результат сложения действительного числа
    @return Результат сложения действительного числа
*/
Complex Complex::operator+(const double& s) {
  Complex r;
  r.Re = Re + s;
  r.Im = Im;
  return r;
}
/*!
    @brief Возвращает результат вычитания действительного числа
    @return Результат вычитания действительного числа
*/
Complex Complex::operator-(const double& s) {
  Complex r(*this);
  r.Re = Re - s;
  return r;
}
/*!
    @brief Возвращает результат умножения комплексного числа
    @return Результат умножения комплексного числа
*/
Complex Complex::operator*(const Complex& o) {
  Complex r;
  r.Re = Re * o.Re - Im * o.Im;
  r.Im = Re * o.Im + Im * o.Re;
  return r;
}
/*!
    @brief Возвращает результат умножения действительного числа
    @return Результат умножения действительного числа
*/
Complex Complex::operator*(const double& s) {
  Complex r;
  r.Re = Re * s;
  r.Im = Im * s;
  return r;
}
/*!
    @brief Возвращает результат деления действительного числа
    @return Результат деления действительного числа
*/
Complex Complex::operator/(const double& s) {
  Complex r;
  r.Re = Re / s;
  r.Im = Im / s;
  return r;
}
/*!
    @brief Ссылаемся на результат сложения комплексного числа
    @return Возврат по значению сложения
*/
Complex& Complex::operator+=(const Complex& o) {
  Re += o.Re;
  Im += o.Im;
  return *this;
}
/*!
    @brief Ссылаемся на результат вычитания комплексного числа
    @return Возврат по значению вычитания
*/
Complex& Complex::operator-=(const Complex& o) {
  Re -= o.Re;
  Im -= o.Im;
  return *this;
}
/*!
    @brief Ссылаемся на результат умножения комплексного числа
    @return Возврат по значению умножения
*/
Complex& Complex::operator*=(const Complex& o) {
  double tmpRe = Re;
  Re = Re * o.Re - Im * o.Im;
  Im = Im * o.Re + tmpRe * o.Im;
  return *this;
}
/*!
    @brief Ссылаемся на результат сложения действительного числа
    @return Возврат по значению сложения
*/
Complex& Complex::operator+=(const double& s) {
  Re += s;
  return *this;
}
/*!
    @brief Ссылаемся на результат вычитания действительного числа
    @return Возврат по значению вычитания
*/
Complex& Complex::operator-=(const double& s) {
  Re -= s;
  return *this;
}
/*!
    @brief Ссылаемся на результат умножения действительного числа
    @return Возврат по значению умножения
*/
Complex& Complex::operator*=(const double& s) {
  Re *= s;
  Im *= s;
  return *this;
}
/*!
    @brief Ссылаемся на результат деления действительного числа
    @return Возврат по значению деления
*/
Complex& Complex::operator/=(const double& s) {
  Re /= s;
  Im /= s;
  return *this;
}
/*!
    @brief Ссылаемся на результат равенства комплексного числа
    @return Возврат по значению равенства
*/
Complex& Complex::operator=(const Complex& o) {
  Re = o.Re;
  Im = o.Im;
  return *this;
}
/*!
    @brief Ссылаемся на результат равенства действительного числа
    @return Возврат по значению равенства
*/
Complex& Complex::operator=(const double& s) {
  Re = s;
  Im = 0.0;
  return *this;
}
/*!
    @brief Извлекаем действительную и мнимую составляющие
    @return Извлечение
*/
istream& operator>>(istream& stream, Complex& c) {
  char tmp[256];
  stream >> c.Re >> c.Im >> tmp;
  return stream;
}
/*!
    @brief Вставляем действительную и мнимую составляющие
    @return Вставление
*/
ostream& operator<<(ostream& stream, Complex& c) {
  stream << c.Re;
  if (!(c.Im < 0)) stream << '+';
  stream << c.Im << 'i';
  return stream;
}
/*!
    @brief Возвращает результат сложения действительного и комплексного чисел
    @param aLval Действительное число
    @return Результат сложения
*/
Complex operator+(const double& s, const Complex& c) {
  Complex r;
  r.Re = s + c.Re;
  r.Im = c.Im;
  return r;
}
/*!
    @brief Возвращает результат вычитания действительного и комплексного чисел
    @return Результат сложения
*/
Complex operator-(const double& s, const Complex& c) {
  Complex r;
  r.Re = s - c.Re;
  r.Im = -c.Im;
  return r;
}
/*!
    @brief Возвращает результат умножения действительного и комплексного чисел
    @return Результат сложения
*/
Complex operator*(const double& s, const Complex& c) {
  Complex r;
  r.Re = s * c.Re;
  r.Im = s * c.Im;
  return r;
}
