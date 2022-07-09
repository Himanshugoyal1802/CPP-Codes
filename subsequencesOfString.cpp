#include <bits/stdc++.h>
using namespace std;

int subsequences(string input , string output[]){
    if(input.size() == 0){
        cout<<" "<<endl;
        return 1;
    }
    string smallSub = input.substr(1);
    int smallInput = subsequences( smallSub , output);

    for(int i=0 ;i <smallInput ; i++){
        output[smallInput + i] = input[0] + output[i];
    }

    return 2*smallInput;
}

int main(){

    string s;
    cin>>s;
    int a = s.size();
    int b = pow(2,a);
    string * output = new string[b];
    int size = subsequences(s,output);
    cout<<size<<endl;

    for(int i=0 ; i<size ; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}