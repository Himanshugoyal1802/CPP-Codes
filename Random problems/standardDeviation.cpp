#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],x=0,z=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x += a[i];
    }
    x = x/n;
    for(int i=0;i<n;i++){
        z += (a[i] - x)*(a[i] - x);
    }
    cout<<sqrt(z/n);
    return 0;
}