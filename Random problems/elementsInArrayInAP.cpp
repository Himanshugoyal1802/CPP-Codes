#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the length : ";
    int n;
    cin>>n;
    cout<<endl;
    cout<<"Enter the step size :";
    int d;
    cin>>d;
    cout<<endl;
    cout<<"Enter the starting point : ";
    int a;
    cin>>a;

    int arr[n];
    arr[0] = a;
    cout<<a<<" ";
    for(int i=1;i<n;i++){
        arr[i] = arr[i-1]+d;
        cout<<arr[i]<<" ";
    }
}