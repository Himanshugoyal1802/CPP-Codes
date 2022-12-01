#include <bits/stdc++.h>
using namespace std;

class Pair{
    public:
        int min;
        int max;
};

Pair minMaxFinder(int input[], int si , int ei ){
    if(si == ei || ei == si+1){   
        Pair ans;
        if(si == ei){
            ans.min = input[si];
            ans.max = input[si];
        }
        else{
            if(input[si]<input[ei]){
                ans.min = input[si];
                ans.max = input[ei];
            }else{
                ans.min = input[ei];
                ans.max = input[si];
            }
        }

        return ans;
    }

    int mid = (ei+si)/2;

    Pair myAns;

    Pair newAns1 = minMaxFinder(input , si , mid);
    Pair newAns2 = minMaxFinder(input, mid+1 , ei);

    if(newAns1.min < newAns2.min){
        myAns.min = newAns1.min;
    }
    else{
        myAns.min = newAns2.min;
    }

    if(newAns1.max > newAns2.max){
        myAns.max = newAns1.max;
    }else{
        myAns.max = newAns2.max;
    }

    return myAns;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Pair ans = minMaxFinder(arr,0,n-1);

    cout<<"Min:"<<ans.min<<endl;
    cout<<"Max:"<<ans.max<<endl;
}