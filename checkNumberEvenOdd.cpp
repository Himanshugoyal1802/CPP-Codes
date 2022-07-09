#include<iostream>
using namespace std;

int main(){

    cout<<"Enter the number :";
    int n;
    cin>>n;

    if(n%2==0){
        cout<<"Number is even.";
    }else{
        cout<<"Number is odd.";
    }
    return 0;
}