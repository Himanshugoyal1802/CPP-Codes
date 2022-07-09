#include<bits/stdc++.h>
using namespace std;

int partition(int input[], int si , int ei){
    int count = 0;
    int pivot = input[si];

    for(int i=si+1; i <= ei ; i++){
        if(input[i]<=pivot){
            count++;
        }
    }

    int a = count + si;
    int temp = input[a];
    input[a] = input[si];
    input[si] = temp;

    int i=si;
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

void quickSortHelper(int input[], int si , int ei){
    if(si>=ei){
        return; 
    }

    int pi = partition(input,si,ei);
    quickSortHelper(input,si,pi-1);
    quickSortHelper(input,pi+1,ei);
}

void quickSort(int input[], int n){
    quickSortHelper(input,0,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    quickSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}