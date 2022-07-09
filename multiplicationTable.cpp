#include <iostream>
using namespace std;

int main(){
    cout<<"Enter the number : ";
    int n;
    cin>>n;
    // 5 X 1 = 5
    for(int i = 1 ;i<=10 ; i++){
        cout<< n<<" X "<<i<<" = "<<n*i<<endl;
    }
    return 0;
}