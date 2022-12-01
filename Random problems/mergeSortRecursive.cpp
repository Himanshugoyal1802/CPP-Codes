#include <iostream>
using namespace std;


void mergeSortHelper(int input[], int si , int ei){
    if(si>ei){
        return;
    }
    if(si == ei){
        return;
    }
    
    int mid = (si+ei)/2;
    
    mergeSortHelper(input,si,mid);
    mergeSortHelper(input,mid+1,ei);
    
    int arr[(ei-si)+1];
    int i = si;
    int j = mid+1;
    int k=0;
    
    while(i<=mid && j<=ei){
        if(input[i]<input[j]){
        arr[k++] = input[i++];
        }else{
            arr[k++] = input[j++];
        }
        
        for(;i<=mid;i++){
            arr[k++] = input[i];
        }
        for(;j<=ei;j++){
            arr[k++] = input[j];
        }
    }

    for(int i=si; i<= ei ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    for(int i=si;i<=ei;i++){
        input[i] = arr[i];
    }
    
}

void mergeSort(int input[], int size){
	// Write your code here


    
	int si = 0;
    int ei = size-1;
    
    mergeSortHelper(input,si,ei);
    
        
}




int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}