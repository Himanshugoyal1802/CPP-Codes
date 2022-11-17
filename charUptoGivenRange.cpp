#include<iostream>
using namespace std;

int main(){
    char c;
    cin>>c;
    int size = c - 65+1;
    char arr[size];
    int a = 65;
    for(int i=0;i<size;i++){
        arr[i] = a++;
        cout<<arr[i]<<" ";
    }
    
}