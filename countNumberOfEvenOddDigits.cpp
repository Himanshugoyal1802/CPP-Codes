#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    int even = 0;
    int odd = 0;
    while(n>0){
        int x = n%10;
        if(x%2==0){
            even++;
        }
        else{
            odd++;
        }
        n = n/10;
    }
    cout<<"Even no of digits: "<<even<<endl;
    cout<<"Odd no of digits: "<<odd;
    return 0;
}