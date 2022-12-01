#include<iostream>
#include<array>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;
    string array[m];
    for(int i=0;i<m;i++){
        cin>>array[i];
    }
    // cout<<arr[0];
    string output[n*m];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            output[k] = arr[i] +" "+ array[j];
            cout<<output[k]<<" , ";
            k = k+1;
        }
    }
}