#include <bits/stdc++.h>
using namespace std;

int binarySearchHelper(int input[], int si, int ei , int element){
    if(ei>=si){
        int mid = (si+ei)/2;

        if(input[mid] == element){
            return mid;
        }
        if(input[mid]<element){
            return binarySearchHelper(input,mid+1,ei,element);
        }
        else{
            return binarySearchHelper(input,si,mid-1,element);
        }
    }
    return -1;
}

int binarySearch(int input[] , int size , int element){
    int si = 0;
    int ei = size-1;
    binarySearchHelper(input,si,ei,element);
}

int main(){
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
    return 0;
}