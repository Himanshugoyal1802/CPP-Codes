#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int even[n];
    int odd[n];
    int e=0,o=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            even[e++] = arr[i];
        }
        else{
            odd[o++] = arr[i];
        }
    }

    for(int i=0;i<n;i++){
        cout<<even[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<odd[i]<<" ";
    }

    return 0;
}