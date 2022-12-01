#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the range : ";
    int x,y;
    cin>>x>>y;
    while(y>=x){
        cout<<y<<" ";
        y = y-2;
    }
}