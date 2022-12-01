#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> m;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int a = 0;
    int b = m[0];
    for(auto i:m){
        if(b<=i.second){
            b = i.second;
            a = i.first;
        }
    }
    cout<<a;
    return 0;

}