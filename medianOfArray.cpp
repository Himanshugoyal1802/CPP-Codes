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
    int mid = n/2;
    if(n % 2 != 0){
        cout<<arr[mid];
    }
    else{
        
        int a = (arr[mid] + arr[mid-1])/2;
        cout<<a<<endl;
    }

}