#include<bits/stdc++.h>
using namespace std;

class Polynomial {
    public:
    
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
	
    Polynomial(){
        degCoeff = new int[5];
        capacity = 5;
        for(int i=0;i<capacity; i++){
            degCoeff[i] = 0;
        }
    }
    
    Polynomial(Polynomial const &p){
        //this->degCoeff = p.degCoeff;			//this is shallow copy
        this->degCoeff = new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    
    void setCoefficient(int deg, int coeff){
        if(deg<capacity){
            degCoeff[deg] = coeff;
        }else{
            int *newArray = new int[2*capacity];
            
            for(int i=0;i<2*capacity;i++){
                newArray[i] = 0;
            }
            
            for(int i=0;i<2*capacity;i++){
                newArray[i] = degCoeff[i];
            }
            delete []degCoeff;
            degCoeff = newArray;
            capacity = 2 * capacity;
            setCoefficient(deg,coeff);
        }
    }
    
    int largeCapacity(Polynomial p , Polynomial p1){
        return max(p.capacity , p1.capacity);
    }
    
    Polynomial operator+(Polynomial const &p){
        int n = largeCapacity(*this , p);
        Polynomial addResult;
        addResult.capacity = n;
        
        for(int i=0;i<n;i++){
            addResult.setCoefficient(i,this->degCoeff[i] + p.degCoeff[i]);
        }
        
        return addResult;
    }
    
    Polynomial operator-(Polynomial const &p){
        int n = largeCapacity(*this , p);
        Polynomial subResult;
        subResult.capacity = n;
        
        for(int i=0;i<n;i++){
            subResult.setCoefficient(i,this->degCoeff[i] - p.degCoeff[i]);
        }
        
        return subResult;
    }
    
    Polynomial operator*(Polynomial const &p){
        Polynomial multiplyResult;
        for(int i=0 ; i < this->capacity ; i++){
            if(this->degCoeff[i] != 0){
                for(int j=0 ; j<p.capacity; j++){
                    if(p.degCoeff[j] != 0){
                		multiplyResult.setCoefficient(i+j , ((this->degCoeff[i])*(p.degCoeff[j]))+multiplyResult.degCoeff[i+j]);
                    }
                }
            }
        }
        return multiplyResult;
    }
    
    void operator=(Polynomial const &p){
        this->degCoeff = new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
        // print(); 
    }
    
	void print(){
        for(int i=0;i<this->capacity; i++){
            if(degCoeff[i] != 0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
};


int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            third.print();
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            fourth.print();
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}