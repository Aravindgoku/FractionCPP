#include "Fraction.h"
#include <iostream>

enum TestCases{
    EqualityCheck=1, NonEqualityCheck=2, GreaterthanCheck=3, LesserthanCheck=4, ValueCheck=5, AdditionCheck=6
};

void assert(int testCase, bool testValue){
        switch(testCase){
        case 1:
            if(testValue){
                std::cout<< "Fraction equality operator value is as expected"<<std::endl;
            } else{
                std::cerr<< "Fraction equality operator value is not as expected"<<std::endl;
            }
            break;
        case 2:
            if(testValue){
                std::cout<< "Fraction non-equality operator value is as expected"<<std::endl;
            } else{
                std::cerr<< "Fraction non-equality operator value is not as expected"<<std::endl;
            }
            break;
        case 3:
            if(testValue){
                std::cout<< "Fraction greater-than operator value is as expected"<<std::endl;
            } else{
                std::cerr<< "Fraction greater-than operator value is not as expected"<<std::endl;
            }
            break;
        case 4:
            if(testValue){
                std::cout<< "Fraction lesser-than operator value is as expected"<<std::endl;
            } else{
                std::cerr<< "Fraction lesser-than operator value is not as expected"<<std::endl;
            }
            break;
        default:
            std::cout<<"Incorrect testCase"<< std::endl;
            break;
    }
}

void assert(int testCase, int expectedNum, int expectedDen, Fraction source){
    switch(testCase){
        case 5:
            if(expectedNum==source.getNumerator() && expectedDen==source.getDenominator()){
                std::cout<< "Values are equal"<<std::endl;
            } else{
                std::cerr<< "Values arent as expected"<<std::endl;
            }
            break;
        case 6:
            if(expectedNum==source.getNumerator() && expectedDen==source.getDenominator()){
                std::cout<< "Fraction addition operator value is as expected"<<std::endl;
            } else{
                std::cerr<< "Fraction addition operator value is not as expected"<<std::endl;
            }
            break;
        default:
            std::cout<<"Incorrect testCase"<< std::endl;
            break;
    }
}

void TEST_FUNCTION(){
    std::cout<<"In Test Function..."<<std::endl;
    
    std::cout<<"\nTesting for Addition of Fractional numbers..."<<std::endl;
    Fraction f1(-4, -8);
    assert(ValueCheck, 1, 2, f1);
    Fraction f2(2, 4);
    assert(ValueCheck, 1, 2, f2);
        
    std::cout<<"\nTesting for Addition of Fractional numbers..."<<std::endl;
    Fraction f3;
    f3 = f1 + f2;
    assert(AdditionCheck, 1, 1, f3);
    f3 = f3 - f2;
    assert(AdditionCheck, 1, 2, f3);
    
    std::cout<<"\nTesting for Comparison of Fractional numbers..."<<std::endl;
    Fraction f4;
    bool testValue = f1==f2;
    assert(EqualityCheck, testValue);
    f3 = f1 + f3;
    testValue = f3 != f1;
    assert(NonEqualityCheck, testValue);
    f1 = f1 + f2;
    testValue = f2 < f1;
    assert(GreaterthanCheck, testValue);
    f3 = f3 + f2;
    testValue = f3 > f2;
    assert(LesserthanCheck, testValue);
    f3.display();
    
    try{
        Fraction f4(5,0);
    }catch(int &ex){
        std::cout<<"\nDivision by zero is not allowed"<<std::endl;
    }
}



int main()
{
    std::cout<<"In Main..."<<std::endl;
    TEST_FUNCTION();
}
