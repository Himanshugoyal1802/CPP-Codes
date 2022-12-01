#include <bits/stdc++.h>
using namespace std;

int partition(int input[], int si, int ei){
    int count = 0;
    int pivot = input[ei];
    for(int i = si; i<ei; i++){
        if(input[i]<=pivot){
            count++;
        }
    }

    int a = ei - count ;
    cout<<a<<endl;
    int temp = input[a];
    input[a] = input[ei];
    input[ei] = temp;
    
    for(int i=si;i<ei;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;

    int i = si;
    int j = ei;
    while(i<a && j>a){
        if(input[i]<= input[a]){
            i++;
        }
        if(input[j] > input[a]){
            j--;
        }
        else{
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return a;
}

void quickSort(int input[], int si , int ei){
    if(si>=ei){
        return;
    }

    int pi = partition(input,si,ei);
    quickSort(input,si,pi-1);
    quickSort(input,pi+1,ei);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}