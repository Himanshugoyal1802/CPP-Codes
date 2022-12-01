#include <bits/stdc++.h>
using namespace std;

void roots(int a, int b, int c){
    int d = pow(b,2) - 4 * a * c;
    if(d>0){
        int x = ((-1)*b + sqrt(d)) / 2*a;
        int y = ((-1)*b - sqrt(d)) / 2*a;

        if(x == y){
            cout<<"Roots are real and same "<<x<<endl;
        }
        else{
            cout<<"Roots are real and different "<<
        }
    }
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    roots(a,b,c);
    return 0;
}