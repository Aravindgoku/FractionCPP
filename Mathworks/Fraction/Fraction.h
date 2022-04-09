#pragma once

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int den);
    Fraction();
    //Fraction(const Fraction &source);
    //template <typename T>
    Fraction operator+(const Fraction &rhs);
    Fraction operator-(const Fraction &rhs);
    Fraction operator*(const Fraction &rhs);
    Fraction operator/(const Fraction &rhs);
    void operator=(const Fraction &rhs);
    
    bool operator==(const Fraction &rhs) const;
    bool operator!=(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    bool operator<(const Fraction &rhs) const;
    ~Fraction();
    
    void display() const;
    
    int getNumerator() const;
    int getDenominator() const;
    
    /*void setNumerator(int);
    void setDenominator(int);*/

};

