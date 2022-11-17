/*
Find the majority element in the array. A majority element in an array A[] of size n is an element 
that appears more than n/2 times (and hence there is at most one such element). 

Examples : 

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is greater than the half of the size of the 
array size.
*/

#include <iostream>
using namespace std;

int nBy2repeatedNumbers(int arr[], int n){
    int ele = -1, cnt = 0;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            ele = arr[i];
        }
        if(arr[i] == ele){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    return ele;
}

int main(){
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Majority Element present more than n/2 times : "<< nBy2repeatedNumbers(arr,n)<<endl;
}