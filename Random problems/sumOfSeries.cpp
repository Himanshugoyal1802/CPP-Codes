#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the value of n: ";
    int n;
    cin>>n;
    cout<<endl;
    cout<<"Enter the value of d: ";
    int d;
    cin>>d;

    int sum = 0;
    int i = 0;
    int a = 0;

    while(i<n){
        a= (d + a*10);
        sum = sum + a;
        i++;
    }

    cout<<sum;
}