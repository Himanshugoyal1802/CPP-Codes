#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s ="";
    while(n>0){
        int a = n%10;
        s += a+'0';
        n = n/10;
    }
    cout<<s;
}