#include <bits/stdc++.h>
using namespace std;

/*
//Recursive Solution
int knapSack(int W, int wt[], int val[], int n){
    if(n == 0 || W == 0){
        return 0;
    }

    if(wt[n-1] <= W){
        return max( (val[n-1] + knapSack(W-wt[n-1] , wt, val ,n-1)) , knapSack(W,wt,val,n-1));
    }
    else{
        return knapSack(W,wt,val,n-1);
    }
}
*/

//Dp solution with Top-down approach
int knapSack(int W, int wt[], int val[], int n){
    vector<vector<int>> dp(W+1, vector<int>(n+1));      //initializing dp

    for(int i=0;i<W+1;i++){                         //Base condition
        for(int j=0;j<n+1;j++){             
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<W+1;i++){             //Choice part
        for(int j=1;j<n+1;j++){
            if(wt[j-1] <= i){           //if wt of current item is less than the curr capacity weight
                dp[i][j] = max( (val[j-1] + dp[i-wt[j-1]][j-1]) ,  dp[i][j-1]); //then i have two choices whether to pick it or leave it
            }
            else{
                dp[i][j] = dp[i][j-1];      //else if wt of current item is more than the capacity then we only leave it
            }
        }
    }

    return dp[W][n];        //returning final answer
}

/*
//Recursive solution with memoization
int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp){
    if(n == 0 || W  == 0){
        dp[W][n] = 0;
        return dp[W][n];
    }

    if(dp[W][n] != -1){
        return dp[W][n];
    }

    if(wt[n-1] <= W){
        dp[W][n] = max( (val[n-1] + helper(W-wt[n-1] , wt, val ,n-1,dp)) , helper(W,wt,val,n-1,dp));
    }
    else{
        dp[W][n] = helper(W,wt,val,n-1,dp);
    }
    return dp[W][n];
}

int knapSack(int W, int wt[], int val[], int n){
    vector<vector<int>> dp(W+1, vector<int>(n+1,-1));
    return helper(W,wt,val,n,dp);
}
*/

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}