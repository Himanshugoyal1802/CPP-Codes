#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rev = 0;
    int copy = n;
    while(n>0){
        int a = n%10;
        rev = a + rev*10;
        n = n/10;
    }

    if(rev == copy){
        cout<<"yes, palindrome.";
    }
    else{
        cout<<"not palindrome.";
    }
}