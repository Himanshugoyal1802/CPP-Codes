#include<bits/stdc++.h>
using namespace std;

/*
    --------Recursive Solution--------
    //TC --> 2^n
    //Sc --> n(recursive stack)

int fib(int n){
    if(n<=1)return n;
    return fib(n-1) + fib(n-2);
}*/

/*
    --------Memoization Solution--------
    //TC --> n;
    //SC --> n(dp array) + n(recursive stack);
int fib(int n, vector<int> &dp){
    if(n<=1)return n;
    if(dp[n]!= -1)return dp[n];

    return dp[n] = fib(n-2,dp) + fib(n-1,dp);
}
*/

/*
    ---Bottom-Up Approach (Dp Solution)
    //TC -->n;
    //SC -->n(dp array)
int fib(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
*/

//Most optimal Approach
//TC-->n
//SC-->1
int fib(int n){
    if(n<=1)return n;
    int prev2 = 0;
    int prev = 1;
    for(int i=2;i<=n;i++){
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}


int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    // int x = fib(n,dp);     //for dp recursive calls;
    int x = fib(n);
    cout<<x<<endl;
}