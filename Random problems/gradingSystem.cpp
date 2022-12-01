#include<iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin>>n;
        if(n == -1){
            break;
        }
        if(n>=90 && n<=100){
            cout<<"Grade A"<<endl;
        }
        if(n>=80 && n<90){
            cout<<"Grade B"<<endl;
        }
        if(n>=70 && n<80){
            cout<<"Grade C"<<endl;
        }
        if(n>=60 && n<70){
            cout<<"Grade E"<<endl;
        }
        if(n<60){
            cout<<"Failed"<<endl;
        }
    }
    return 0;
}