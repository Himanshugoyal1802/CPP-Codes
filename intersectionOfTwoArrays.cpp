#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    int size = n < m ? n : m;
    sort(a,a+n);
    sort(b,b+n);
    int c[size];
    for(int i=0;i<size;i++){
        if(a[i]==b[i]){
            c[i] = a[i];
            cout<<c[i]<<" ";
        }
    }

}