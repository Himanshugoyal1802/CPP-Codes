#include<iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }

    for(auto i:m){
        if(i.second>1){
            cout<<i.first<<"--->"<<i.second<<endl;
        }
    }
}