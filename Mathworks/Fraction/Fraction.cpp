#include "Fraction.h"
#include<numeric>
#include <climits>

/**
 * @brief Overloaded Fraction constructor
 * @param num
 * @param den
 */
Fraction::Fraction(int num, int den){
    if (den == 0)
        throw std::overflow_error("Divide by zero exception");
    if (num==0){
        numerator = 0;
        denominator = 1;
    } else{
        int localGCD = std::gcd(num, den);
        int sign = 1;
        if (num < 0) {
            sign *= -1;
            num *= -1;
        }
        if (den < 0) {
            sign *= -1;
            den *= -1;
        }
        numerator = num*sign/localGCD;
        denominator = den/localGCD;
    }
    
}

Fraction::Fraction():Fraction(0, 1)
{
}

/**
 * @brief Overloaded insertion operator to display the fraction object
 * @return 
 */
std::ostream &operator<<(std::ostream &os, const Fraction &rhs){
    if (rhs.denominator != 1){
        os << rhs.numerator << "/" << rhs.denominator;
    } else {
        os << rhs.numerator;
    }
    return os;
}

int Fraction::getNumerator() const{
    return numerator;
}

int Fraction::getDenominator() const{
    return denominator;
}

/**
 * @brief Overloaded plus operator to add two fraction objects
 * @param rhs
 * @return (numerator*rhs.denominator + rhs.numerator*denominator)/(denominator*rhs.denominator)
 */
Fraction Fraction::operator+(const Fraction& rhs) const{
    int denVal, temp1, temp2, numVal;
    multiplicationCheck(numerator, rhs.denominator, temp1);
    multiplicationCheck(rhs.numerator, denominator, temp2);
    additionCheck(temp1, temp2, numVal);
    multiplicationCheck(denominator, rhs.denominator, denVal);
    
    return Fraction(numVal,denVal);
}

Fraction Fraction::operator-(const Fraction& rhs) const{
    int denVal, temp1, temp2, numVal;
    multiplicationCheck(numerator, rhs.denominator, temp1);
    multiplicationCheck(rhs.numerator, denominator, temp2);
    additionCheck(temp1, (-1)*temp2, numVal);
    multiplicationCheck(denominator, rhs.denominator, denVal);
    
    return Fraction(numVal,denVal);
}

Fraction Fraction::operator*(const Fraction& rhs) const{
    int denVal,numVal;
    multiplicationCheck(numerator, rhs.numerator, numVal);
    multiplicationCheck(denominator, rhs.denominator, denVal);
    
    return Fraction(numVal, denVal);
}

Fraction Fraction::operator/(const Fraction& rhs) const{
    int denVal,numVal;
    multiplicationCheck(numerator, rhs.denominator, numVal);
    multiplicationCheck(denominator, rhs.numerator, denVal);
    
    return Fraction(numVal, denVal);
}

bool Fraction::operator==(const Fraction &rhs) const{
    int num1,num2;
    multiplicationCheck(numerator, rhs.denominator, num1);
    multiplicationCheck(denominator, rhs.numerator, num2);
    
    return num1 == num2;
}

bool Fraction::operator!=(const Fraction &rhs) const{
    
    return !((*this) == rhs);
}


bool Fraction::operator<(const Fraction &rhs) const{
    int num1,num2;
    multiplicationCheck(numerator, rhs.denominator, num1);
    multiplicationCheck(denominator, rhs.numerator, num2);
    
    return num1 < num2;
}

bool Fraction::operator>(const Fraction &rhs) const{

    return !((*this) < rhs);
}

/**
 * @brief To check for integer overflow during Math operations.
 * @param num1
 * @param num2
 * @param result
 */
void additionCheck(int num1, int num2, int &result){
    long long sumVal = static_cast<long long>(num1) + static_cast<long long>(num2);
    if ((sumVal >= INT_MIN) || (sumVal <= INT_MAX)){
        result = static_cast<int>(sumVal);
        return;
    } else{
        throw std::overflow_error("Integer overflow exception");
    }
}

void multiplicationCheck(int num1, int num2, int &result){
    long long multVal = static_cast<long long>(num1) * static_cast<long long>(num2);
    if ((multVal >= INT_MIN) || (multVal <= INT_MAX)){
        result = static_cast<int>(multVal);
        return;
    } else{
        throw std::overflow_error("Integer overflow exception");
    }
}
