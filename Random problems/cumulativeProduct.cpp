#include<iostream>
using namespace std;

int main(){
    int x = 1;
    while(true){
        
        int n;
        cin>>n;

        if(n == -1){
            break;
        }
        
        cout<<n*x<<endl;
        x = n;
        
    }
    return 0;
}