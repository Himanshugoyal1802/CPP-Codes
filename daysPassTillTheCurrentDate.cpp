#include<iostream>
#include<ctime>
using namespace std;
int main(){
    cout<<"Enter your name please :";
    string name;
    getline(cin,name);
    cout<<endl;
    // cout<<"Enter the current date :";

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    // int dd,mm,yyyy;
    // cin>>dd>>mm>>yyyy;

    int totalDays = (now->tm_mon)*30 + now->tm_mday + 1;

    cout<<"Hello "<<name<<","<<endl;
    cout<<"welcome to the "<<totalDays<<"th day of the year "<<now->tm_year + 1900<<endl;
    return 0;
}