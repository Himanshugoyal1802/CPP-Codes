#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int min1 = INT_MAX ,min2= INT_MAX;
    int max1 = INT_MIN ,max2 = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]<min1){
            if(arr[i]<min2){
                min1 = min2;
                min2 = arr[i];
            }
            else{
                min1 = arr[i];
            }
        }
        if(arr[i]>max1){
            
                if(arr[i]>max2){
                    max1= max2;
                    max2 = arr[i];
                }
                else{
                    max1 = arr[i];
                }
            
        }
    }

    cout<<"Min product : "<<min1*min2<<endl;
    cout<<"Max product : "<<max1*max2<<endl;
}