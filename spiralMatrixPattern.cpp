#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
        cout<<endl;
    }

    int i=0,j=0,k=1;
    while(j<n){
        arr[i][j++] = k++;
    }
    i++,j--;
    while(i<n){
        arr[i++][j] = k++;
    }
    i--,j--;
    while(j>=0){
        arr[i][j--] = k++;
    }
    j++,i--;
    while(i>0){
        arr[i--][j] = k++;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                cout << " "<<" ";
            }
            else cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}