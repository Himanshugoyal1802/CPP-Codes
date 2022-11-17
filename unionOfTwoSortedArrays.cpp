#include<iostream>
#include<vector>
using namespace std;

// int unionOfArrays(int arr[], int n, int array[], int m, vector<int> & rslt){
//     // int x = n + m;
//     int i, j =0;
//     for(;i<n,j<m;i++,j++){
//         if(arr[i] == array[j]){
//             rslt.push_back(arr[i]);
//         }
//         else{
//             rslt.push_back(arr[i]);
//             rslt.push_back(array[j]);
//         }
//     }
//     for(;i<n;i++){
//         rslt.push_back(arr[i]);
//     }
//     for(;j<m;j++){
//         rslt.push_back(array[j]);
//     }
//     cout<<rslt.size();
//     for(int i=0;i<rslt.size();i++){
//         cout<<rslt[i]<<" ";
//     }
//     return rslt.size();
// }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;
    int array[m];
    for(int i=0;i<m;i++){
        cin>>array[i];
    }

    vector<int> rslt;
    int i=0, j =0;
    while(i<n && j<m){
        if(arr[i] == array[j]){
            rslt.push_back(arr[i]);
            i++,j++;
        }
        else if(arr[i]<array[j]){
            rslt.push_back(arr[i]);
            i++;
        }
        else{
            rslt.push_back(array[j]);
            j++;
        }
    }
    for(;i<n;i++){
        rslt.push_back(arr[i]);
    }
    for(;j<m;j++){
        rslt.push_back(array[j]);
    }
    // cout<<rslt.size();
    for(int i=0;i<rslt.size();i++){
        cout<<rslt[i]<<" ";
    }
}