#include "Complex.h"
#include "pch.h"

ComplexNumber::ComplexNumber(double number) {
    real_num = number;
    imag_part = 0;
}
ComplexNumber::ComplexNumber(RationalNumber real_num, RationalNumber imag_part) {
    this->real_num = real_num;
    this->imag_part = imag_part;
}
ComplexNumber::ComplexNumber(const ComplexNumber& other) {
    real_num = other.real_num;
    imag_part = other.imag_part;
}
ComplexNumber::~ComplexNumber() {}
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
    real_num = other.real_num;
    imag_part = other.imag_part;
    return *this;
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    RationalNumber new_real = real_num + other.real_num;
    RationalNumber new_image = imag_part + other.imag_part;
    return ComplexNumber(new_real, new_image);
}
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other) {
    *this = *this + other;
    return *this;
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    RationalNumber new_real = real_num - other.real_num;
    RationalNumber new_image = imag_part - other.imag_part;
    return ComplexNumber(new_real, new_image);
}
ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other) {
    *this = *this - other;
    return *this;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    RationalNumber new_real =
        real_num * other.real_num - imag_part * other.imag_part;
    RationalNumber new_image =
        real_num * other.imag_part + imag_part * other.real_num;
    return ComplexNumber(new_real, new_image);
}
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other) {
    *this = *this * other;
    return *this;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    RationalNumber null;
    if (other.real_num == null && other.imag_part == null) {
        throw std::exception("Division by zero!");
    }
    RationalNumber div = other.real_num.Sqt() + other.imag_part.Sqt();
    RationalNumber new_real = (real_num * other.real_num + imag_part * other.imag_part) / div;
    RationalNumber new_image = (imag_part * other.real_num - real_num * other.imag_part) / div;
    return ComplexNumber(new_real, new_image);
}
ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other) {
    *this = *this / other;
    return *this;
}
const bool operator==(const ComplexNumber& our, const ComplexNumber& other) {
    return our.real_num == other.real_num && our.imag_part == other.imag_part;
}
const bool operator!=(const ComplexNumber& our, const ComplexNumber& other) {
    return (our.real_num != other.real_num || our.imag_part != other.imag_part);
}
ComplexNumber ComplexNumber::operator-() const {
    return ComplexNumber(-real_num, -imag_part);
}
RationalNumber ComplexNumber::Abs() const {
    return RationalNumber((real_num.Sqt() + imag_part.Sqt()).Sqrt());
}
RationalNumber ComplexNumber::Arg() const {
    RationalNumber PI = acos(-1.0);
    RationalNumber arg_result = RationalNumber(imag_part / real_num).Atan();
    if (real_num < 0 && imag_part >= 0) {
        arg_result += PI;
    }
    else if (real_num < 0 && imag_part < 0) {
        arg_result -= PI;
    }
    return arg_result;
}
ComplexNumber ComplexNumber::Pow(int power) {
    ComplexNumber result(real_num, imag_part);
    ComplexNumber complex_pow(real_num, imag_part);
    for (int i = 1; i < power; i++) {
        result *= complex_pow;
    }
    return result;
}
std::ostream& operator<<(std::ostream& out, const ComplexNumber& complex) {
    return out << "ComplexNumber(" << complex.real_num << ", " << complex.imag_part << ")";
}
void ComplexNumber::SetReal(RationalNumber real_num) {
    this->real_num = real_num;
}
void ComplexNumber::SetImag(RationalNumber imag_part) {
    this->imag_part = imag_part;
}
RationalNumber ComplexNumber::GetReal() { return real_num; }
RationalNumber ComplexNumber::GetImag() { return imag_part; }