#include<iostream>
#include<vector>
#include<unordered_map>
#include "checkPasswordStrength.cpp"
using namespace std;
unordered_map <string,string> data;
vector<pair<string,string>> database;

void signup();

void pushData(pair<string,string> p){
    database.push_back(p);
    data[p.first] = p.second;
}

void usersData(){
    pair<string,string> p = {"himanshu", "P@ss123"};
    pair<string,string> q = {"kartik", "K@rtik34"};
    pair<string,string> r = {"dhroov", "@Chapri56"};
    pair<string,string> s = {"ishan", "@Catering67"};
    pair<string,string> t = {"navket", "P@sli24"};
    database.push_back(p);
    database.push_back(q);
    database.push_back(r);
    database.push_back(s);
    database.push_back(t);
    for(pair<string,string> a : database){
        data[a.first] = a.second;
    }  
}
void login(){
    bool flag = true;
    while(flag){
        cout<<"Enter username : ";
        string username;
        cin>>username;
        cout<<endl;
        cout<<"Enter the password please : ";
        string pwd;
        cin>>pwd;
        if(data.find(username) != data.end()){
            if(data[username] == pwd){
                cout<<"Login successful!!"<<endl;
                flag = false;
            }
            else{
                cout<<"Wrong password entered, please try again!"<<endl;
                continue;
            }
        }
        else{
            cout<<"Username not registered , please register."<<endl;
            signup();
        }
    }
    
}
void signup(){
    cout<<"Enter username , with which u want to register: ";
    string username;
    cin>>username;
    cout<<endl;

    if(data.find(username) != data.end()){
        cout<<"Already registered username, Please login!!"<<endl;
        login(); 
    }
    else{
        bool flag = true;
        while(flag){
            cout<<"Enter the password please : ";
            string pwd;
            cin>>pwd;
            if(checkPasswordStrength(pwd)>=3){
                flag = false;
                // data[username] = pwd;
                pair<string,string> p={username,pwd};
                pushData(p);
                cout<<"Registered Successfully!!"<<endl;
                cout<<"Login please : "<< endl;
                login();
            }
            else{
                cout<<"Password strength is low, try with another strong password."<<endl;
            }
        }
    }
    
}

int main(){
    cout<<"For login enter 1 and for signup enter 2"<<endl;
    int n;
    cin>>n;
    switch (n)
    {
    case 1:
        usersData();
        login();
        break;
    
    case 2:
        usersData();
        signup();
        break;
    }

    // for(auto i : database){
    //     cout<<i.first<<"----"<<i.second<<endl;
    // }
    
    return 0;
}