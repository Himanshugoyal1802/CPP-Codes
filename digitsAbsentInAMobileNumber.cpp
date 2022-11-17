#include<iostream>
using namespace std;

void intoArray(long long n,int arr[],int size){
    if(size == 0){
        return;
    }
    int a = n%10;
    arr[a]++;
    intoArray(n/10,arr,size-1); 
}

int main(){
    long long n;
    cout<<"Enter the Mobile Number : ";
    cin>>n;
      
    int arr[10];
    int size = 10;
    for(int i=0;i<10;i++){
        arr[i] = 0;
    }
    intoArray(n,arr,size);
    for(int i=0;i<10;i++){
        if(arr[i]==0){
            cout<<i;
        }
    }
    

}