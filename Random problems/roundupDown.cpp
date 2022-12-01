/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    double p;
    cin>>p;
    // with function
    cout<<"up "<<fixed<<setprecision(2)<<p+0.01<<endl;
    cout<<"down "<<fixed<<setprecision(2)<<p;
    return 0;
}

