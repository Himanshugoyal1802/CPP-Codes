
#include <bits/stdc++.h>

using namespace std;

void nextGreaterElement(vector<int> & arr){
    vector<int> right(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        right[i] = -1;
    }
    
    stack<int> s;
    s.push(0);
  
    for(int i = 1; i<arr.size(); i++){
        int front = s.top();
        while(!s.empty() && arr[front] < arr[i]){
            right[front] = arr[i];
            s.pop();
            if(!s.empty()){
                front = s.top();
            }
        }
        s.push(i);
    }
    cout<<"next greater elements : ";
    for(int i=0;i<right.size();i++){
        cout<<right[i]<<" ";
    }
    
    
}

int main()
{
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};
    cout<<"Initial Array : ";
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    nextGreaterElement(arr);

    return 0;
}
