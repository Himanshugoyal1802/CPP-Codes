/*
We are given a read only array of n integers. Find any element that appears more than n/3 times 
in the array in linear time and constant additional space. If no such element exists, return -1.

Examples:  

Input : [10, 10, 20, 30, 10, 10]
Output : 10
10 occurs 4 times which is more than 6/3.

Input : [20, 30, 10, 10, 5, 4, 20, 1, 2]
Output : -1
*/

#include<iostream>
using namespace std;

int appearsNBy3(int arr[], int n){
    int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n ;i++){
        if(arr[i] == ele1){
            cnt1++;
        }
        else if(arr[i] == ele2){
            cnt2++;
        }
        else if(cnt1 = 0){
            ele1 = arr[i];
            cnt1++;
        }
        else if(cnt2 == 0){
            ele2 = arr[i];
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }

    int count1 = 0, count2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == ele1){
            count1++;
        }
        else if(arr[i] == ele2){
            count2++;
        }
    }

    if(count1 > n/3)return ele1;
    if(count2 > n/3) return ele2;
    return -1;
    
}

int main(){
    int arr[] = {20, 30, 10, 10, 5, 4, 20, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< "The majority Element is : "<<appearsNBy3(arr,n)<<endl;
    return 0;
}
