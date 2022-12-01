#include <iostream>
#include<stack> 
using namespace std;


void nextSmallerElement(int arr[],int n){
    stack<int>s;
    int temp[n]={0};
    s.push(0);
    int i = 1;
    for(;i<n;i++){  
        int front = s.top();
        while(!s.empty() && arr[front] > arr[i]){
            temp[front] = arr[i];
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
