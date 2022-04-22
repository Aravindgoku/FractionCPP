/**
 * @class Fraction
 * @author Aravind S
 * @date 04/21/2022
 * @file Fraction.h
 * @brief Fraction class that performs basic math operations between fraction objects.
 * Throws Integer overflow and Divide by zero exception through std::overflow_error class
 */
#pragma once
#include <iostream>
#include <stdexcept>

class Fraction
{
    
    friend std::ostream& operator<<(std::ostream &os, const Fraction &rhs);
    
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int den);
    Fraction();
    Fraction operator+(const Fraction &rhs) const;
    Fraction operator-(const Fraction &rhs) const;
    Fraction operator*(const Fraction &rhs) const;
    Fraction operator/(const Fraction &rhs) const;
    //void operator=(const Fraction &rhs);
    
    bool operator==(const Fraction &rhs) const;
    bool operator!=(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    bool operator<(const Fraction &rhs) const;
        
    int getNumerator() const;
    int getDenominator() const;

};

    void multiplicationCheck(int num1, int num2, int &result);
    void additionCheck(int num1, int num2, int &result);
