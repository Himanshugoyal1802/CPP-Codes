#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    int n ;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        pq.push(arr[i]);
    }
    int sum = 0;
    for(int i = 0;i<3;i++){
        int a = pq.top();
        sum += a;
        cout<<a<<endl;
        pq.pop();
    }
    cout<< sum/3;
    return 0;
}