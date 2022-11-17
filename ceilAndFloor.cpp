#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    double arr[n];
    int c[n],f[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>0){
            c[i] = arr[i]+1;
            f[i] = arr[i];
        }
        else{
            c[i] = arr[i];
            f[i] = arr[i]-1;
        }
    }
    cout<<"Ceil values : "<<endl;
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    cout<<"floor values : "<<endl;
    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
    }
    
}