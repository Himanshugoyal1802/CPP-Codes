#include <bits/stdc++.h>
using namespace std;

class Fraction{
    private:
    int numerator;
    int denominator;

    public:
    Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print() const{
        cout<<"Fraction: "<<this->numerator<<" / "<<denominator<<endl;
    }

    void simplify() {
        int gcd = 1;
        int small = min(this->numerator , this->denominator);
        for(int i=1; i<small; i++){
            if(this->numerator % i == 0 && this->denominator % i ==0){
                gcd = i;
            }
        }

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    void add(Fraction f2){          //here fraction f2 will create a copy(using copy constructor) of f2 object of fraction class in main function 
        int lcm = denominator * (f2.denominator);       //(refer to upper line) so to prevent the new making of f2 we will use pass by reference as show in multiply function 
        int x = (lcm/denominator) * numerator;
        int y = (lcm/f2.denominator) * (f2.numerator);
        numerator = x + y;
        denominator = lcm;
        simplify();
    }

    //Fraction addTwoFraction(Fraction const &f){       //normal method to add two fraction by making a function like this
    Fraction operator+(Fraction const &f){          //this is operator overloading (similarly we can use -,*,/,==,etc. opertors like this)
        int lcm = denominator * (f.denominator);        
        int x = (lcm/denominator) * numerator;
        int y = (lcm/f.denominator) * (f.numerator);

        int newNumerator = x+y;
        int newDenominator = lcm;

        Fraction fNew(newNumerator, newDenominator);
        fNew.simplify();
        return fNew;
    }

    void multiply(Fraction const &f3){      //const word is used here so that we can only access the value of object , unable to change its value
        this->numerator = numerator * (f3.numerator);
        this->denominator = denominator * (f3.denominator);

        simplify();
    }
};
