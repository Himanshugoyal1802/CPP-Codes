#include <bits/stdc++.h>
using namespace std;
#include "fractionClassOOPS.cpp"

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    //Fraction f3 = f1.addTwoFraction(f2);        //adding two fraction and making it new fraction by simple method

    Fraction f3 = f1 + f2;          //adding two fraction by operator overloading
    f1.print();
    f2.print();
    f3.print();
}