#include "Fraction.h"
#include<numeric>
#include<iostream>

Fraction::Fraction(int num, int den){//:numerator{num}, denominator{den}{
    if (den == 0)
        throw 0;
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

Fraction::~Fraction()
{
}

int Fraction::getNumerator() const{
    return numerator;
}

int Fraction::getDenominator() const{
    return denominator;
}

void Fraction::operator=(const Fraction &rhs){

    numerator = rhs.numerator;
    denominator = rhs.denominator;
}

Fraction Fraction::operator+(const Fraction& rhs) {

    return Fraction(numerator*rhs.denominator
                +rhs.numerator*denominator,
                denominator*rhs.denominator);
}

Fraction Fraction::operator-(const Fraction& rhs) {

    return Fraction(numerator*rhs.denominator
                -rhs.numerator*denominator,
                denominator*rhs.denominator);
}

Fraction Fraction::operator*(const Fraction& rhs) {

    return Fraction(numerator*rhs.numerator,
                denominator*rhs.denominator);
}

Fraction Fraction::operator/(const Fraction& rhs) {

    return Fraction(numerator*rhs.denominator,
                denominator*rhs.numerator);
}

bool Fraction::operator==(const Fraction &rhs) const{
    
    return (numerator * rhs.denominator) == (rhs.numerator * denominator);
}

bool Fraction::operator!=(const Fraction &rhs) const{
    
    return (numerator * rhs.denominator) != (rhs.numerator * denominator);
}


bool Fraction::operator<(const Fraction &rhs) const{
    
    return (numerator * rhs.denominator) < (rhs.numerator * denominator);
}

bool Fraction::operator>(const Fraction &rhs) const{
    
    return (numerator * rhs.denominator) > (rhs.numerator * denominator);
}

void Fraction::display() const{
    std::cout << "Value of the fraction is " << numerator << "/" << denominator << std::endl;
}