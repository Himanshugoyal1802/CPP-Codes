#include<iostream>
using namespace std;

void fib(int n){
    int a = 0;
    int b = 1;
    cout << a<<" "<<b<<" ";
    int c;
    int i = 0;
    while(i<n-2){
        c = a+b;
        cout<<c<<" ";
        a = b;
        b = c;
        i++;
    }

}

int main(){

    int n;
    cin>>n;
    fib(n);
    return 0;
}