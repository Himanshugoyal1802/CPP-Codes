#include<iostream>
using namespace std;
#define lac 100000 ;
// 5lac----5%
// 10lac----10%
// 10+----20%
int main(){
    cout<<"Enter your income please : ";
    int n;
    cin>>n;

    int tax = 0;
    if(n<=5){
        cout<<"No need to pay tax!"<<endl;
        return 0;
    }
    if(n>10){
        int a = (n-10);
        n = n - a;
        a = a * lac;
        tax += a /5;
        cout<<tax<<endl;
        
    }
    if(n>5){
        int b = (n-5);
        n = n-b;
        b = b * lac;
        tax += b / 10;
        cout<<tax<<endl;
        
    }
    if(n<=5){
        n = n* lac;
        tax += n / 20;
        cout<<tax<<endl;
    }

    cout<<"Tax you have to pay : "<<tax ;
    return 0;
}