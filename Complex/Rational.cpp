#include "Rational.h"
#include "pch.h"

RationalNumber::RationalNumber() {}
RationalNumber::RationalNumber(double number) {
    if (number == static_cast<int64_t>(number)) {
        numerator = static_cast<int64_t>(number);
        denominator = 1;
    }
    else {
        std::ostringstream str;
        str << number;
        std::string decimal = str.str();
        std::string after_point = decimal.substr(decimal.find('.') + 1);
        int lenght = after_point.length();

        for (; lenght > 0; lenght--) {
            number *= 10;
            denominator *= 10;
        }
        numerator = number;
        Reduction();
    }
}
RationalNumber::RationalNumber(int64_t numerator, int64_t denominator) {
    if (denominator != 0) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    if (this->denominator <= 0) {
        this->denominator = -this->denominator;
        this->numerator = -this->numerator;
    }
    if (this->numerator != 0) {
        Reduction();
    }
    else {
        this->denominator = 1;
    }
}
int64_t RationalNumber::GreatestCommonFactor(int64_t number_one,
    int64_t number_two) {
    while (number_one != number_two) {
        if (number_one > number_two) {
            int64_t support = number_one;
            number_one = number_two;
            number_two = support;
        }
        number_two -= number_one;
    }
    return number_one;
}
void RationalNumber::Reduction() {
    int64_t div = GreatestCommonFactor(abs(numerator), denominator);
    numerator /= div;
    denominator /= div;
}
RationalNumber& RationalNumber::operator=(const RationalNumber& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}
const RationalNumber operator+(const RationalNumber& our,
    const RationalNumber& other) {
    int64_t new_num, new_den;
    if (our.denominator != other.denominator) {
        new_num =
            our.numerator * other.denominator + other.numerator * our.denominator;
        new_den = our.denominator * other.denominator;
    }
    else {
        new_num = our.numerator + other.numerator;
        new_den = our.denominator;
    }
    return RationalNumber(new_num, new_den);
}
RationalNumber& RationalNumber::operator+=(const RationalNumber& other) {
    *this = *this + other;
    return *this;
}
const RationalNumber operator-(const RationalNumber& our,
    const RationalNumber& other) {
    int64_t new_num, new_den;
    if (our.denominator != other.denominator) {
        new_num =
            our.numerator * other.denominator - other.numerator * our.denominator;
        new_den = our.denominator * other.denominator;
    }
    else {
        new_num = our.numerator - other.numerator;
        new_den = our.denominator;
    }
    return RationalNumber(new_num, new_den);
}
RationalNumber& RationalNumber::operator-=(const RationalNumber& other) {
    *this = *this - other;
    return *this;
}
const RationalNumber operator*(const RationalNumber& our,
    const RationalNumber& other) {
    return RationalNumber(our.numerator * other.numerator,
        our.denominator * other.denominator);
}
const RationalNumber operator/(const RationalNumber& our,
    const RationalNumber& other) {
    return RationalNumber(our.numerator * other.denominator,
        our.denominator * other.numerator);
}
const bool operator==(const RationalNumber& our, const RationalNumber& other) {
    return our.numerator == other.numerator &&
        our.denominator == other.denominator;
}
const bool operator!=(const RationalNumber& our, const RationalNumber& other) {
    return !(our == other);
}
RationalNumber RationalNumber::operator-() const {
    return RationalNumber(-numerator, denominator);
}
const bool operator<(const RationalNumber& our, const RationalNumber& other) {
    return our.numerator * other.denominator < other.numerator* our.denominator;
}
const bool operator>=(const RationalNumber& our, const RationalNumber& other) {
    return !(our < other);
}
RationalNumber RationalNumber::Sqrt() const {
    return RationalNumber(sqrt(numerator) / sqrt(denominator));
}
RationalNumber RationalNumber::Sqt() const {
    return RationalNumber(numerator * numerator, denominator * denominator);
}
std::ostream& operator<<(std::ostream& out, const RationalNumber& rational) {
    return out << rational.numerator << "/" << rational.denominator;
}
RationalNumber RationalNumber::Atan() const {
    return atan(static_cast<double>(numerator) /
        static_cast<double>(denominator));
}
std::string RationalNumber::GetFraction() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

double RationalNumber::GetDouble() const
{
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}
