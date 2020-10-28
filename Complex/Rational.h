#pragma once
#include <cstdint>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


class RationalNumber {
    int64_t numerator = 0;
    int64_t denominator = 1;
public:
    RationalNumber();

    RationalNumber(double number);

    RationalNumber(int64_t numerator, int64_t denominator);

    int64_t GreatestCommonFactor(int64_t number_one, int64_t number_two);

    void Reduction();

    RationalNumber& operator=(const RationalNumber& other);

    friend const RationalNumber operator+(const RationalNumber& our, const RationalNumber& other);

    RationalNumber& operator+=(const RationalNumber& other);

    friend const RationalNumber operator-(const RationalNumber& our, const RationalNumber& other);

    RationalNumber& operator-=(const RationalNumber& other);

    friend const RationalNumber operator*(const RationalNumber& our, const RationalNumber& other);

    friend const RationalNumber operator/(const RationalNumber& our, const RationalNumber& other);

    friend const bool operator==(const RationalNumber& our, const RationalNumber& other);

    friend const bool operator!=(const RationalNumber& our, const RationalNumber& other);

    RationalNumber operator-() const;

    friend const bool operator<(const RationalNumber& our, const RationalNumber& other);


    friend const bool operator>=(const RationalNumber& our, const RationalNumber& other);

    RationalNumber Sqrt() const;

    RationalNumber Sqt() const;

    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& rational);

    RationalNumber Atan() const;

    std::string GetFraction() const;

    double GetDouble() const;
};