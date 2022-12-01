#include <iostream>
#include<stack> 
using namespace std;


void nextSmallerElement(int arr[],int n){
    stack<int>s;
    int temp[n]={0};
    s.push(n-1);
    int i = n-2;
    for(;i>=0;i--){
        int front = s.top();
        while(!s.empty() && arr[front] > arr[i]){
            temp[front] = i;
            s.pop();
            if(!s.empty()){
                front = s.top();
            }
        }
        s.push(i);
    }
    for(int i : temp){
        cout<<i<<" ";
    }
    
}

int main()
{
    int arr[]= {4, 8, 5, 2, 25};
    nextSmallerElement(arr,5);

    return 0;
}
