#include<iostream>
#include<string>
using namespace std;

//length>=8 ---- 1
//combination of upper lower letter ----1
//combination of alphabets and digits ----1
//use of special character ----1


int checkPasswordStrength(string pwd){
    int strength = 0;
    int length = pwd.size();

    if(length>=8){
        strength++;
    }
    int upper=0,lower=0,digit=0,specialChar=0;
    for(int i=0;i<length;i++){
        if(pwd[i]>=65 && pwd[i]<=90){
            upper++;
        }
        else if(pwd[i]>=97 && pwd[i]<=122){
            lower++;
        }
        else if(pwd[i]>=48 && pwd[i]<=57){
            digit++;
        }
        else{
            specialChar++;
        }
    }

    if(upper>0 && lower>0){
        strength++;
    }
    if((upper>0 || lower>0) && digit>0){
        strength++;
    }
    if(specialChar>0){
        strength++;
    }

    return strength;

}

// int main(){
//     cout<<"Enter the password please : ";
//     string pwd;
//     cin>>pwd;

//     cout<<"Your Password Strength is : "<< checkPasswordStrength(pwd);
//     return 0;
// }