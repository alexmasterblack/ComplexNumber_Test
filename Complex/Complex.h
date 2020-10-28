#pragma once
#include "Rational.h"
#include <exception>

class ComplexNumber {
private:
    RationalNumber real_num;
    RationalNumber imag_part;
public:
    ComplexNumber(double number = 0);

    ComplexNumber(RationalNumber real_num, RationalNumber imag_part);

    ComplexNumber(const ComplexNumber& other);

    ~ComplexNumber();

    ComplexNumber& operator=(const ComplexNumber& other);

    ComplexNumber operator+(const ComplexNumber& other) const;

    ComplexNumber& operator+=(const ComplexNumber& other);

    ComplexNumber operator-(const ComplexNumber& other) const;

    ComplexNumber& operator-=(const ComplexNumber& other);

    ComplexNumber operator*(const ComplexNumber& other) const;

    ComplexNumber& operator*=(const ComplexNumber& other);

    ComplexNumber operator/(const ComplexNumber& other) const;

    ComplexNumber& operator/=(const ComplexNumber& other);

    friend const bool operator==(const ComplexNumber& our, const ComplexNumber& other);

    friend const bool operator!=(const ComplexNumber& our, const ComplexNumber& other);

    ComplexNumber operator-() const;

    RationalNumber Abs() const;

    RationalNumber Arg() const;

    ComplexNumber Pow(int power = 2);

    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& complex);

    void SetReal(RationalNumber real_num);

    void SetImag(RationalNumber imag_part);

    RationalNumber GetReal();

    RationalNumber GetImag();
};

