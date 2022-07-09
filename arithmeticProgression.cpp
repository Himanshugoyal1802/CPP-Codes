#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int d = arr[1]-arr[0];
    for(int i = 2; i<n; i++){
        if(arr[i]-arr[i-1] != d){
            cout<<"no, the elements of array are not consecutive."<<endl;
            return 0;

        }
    }
    
    cout<<"yes, the elements of array are consecutive";
    return 0;

}