#include<bits/stdc++.h>
using namespace std;

/*
        //Recursive code
        bool helper(vector<int> arr, int sum, int n){
            if((n == 0 && sum == 0)  || (n != 0 && sum == 0))return true;
            if(n == 0 && sum != 0)return false;
            
            if(arr[n-1] <= sum){
                return helper(arr,sum-arr[n-1],n-1) || helper(arr,sum,n-1);
            }
            else{
                return helper(arr,sum,n-1);
            }
        }
    
        bool isSubsetSum(vector<int>arr, int sum){
            return helper(arr,sum,arr.size());
        }
        
        <----------------------------------------------------------------------------->
        
        //Recursive Memoization code
        bool helper(vector<int> arr, int sum, int n, vector<vector<int>> &dp){
            if((n == 0 && sum ==0) || (n!=0 && sum == 0))return true;
            if(n==0 && sum != 0)return false;
            
            if(arr[n-1] <= sum){
                dp[n][sum] = helper(arr,sum-arr[n-1],n-1,dp) || helper(arr,sum,n-1,dp);
            }
            else{
                dp[n][sum] = helper(arr,sum,n-1,dp);
            }
            return dp[n][sum];
        }
        
    
        bool isSubsetSum(vector<int>arr, int sum){
            // code here
            int n = arr.size();
            vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
            
            return helper(arr,sum,n,dp);
        }
        
    */


//dp solution (top-down approach)
 bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1 , vector<int>(sum+1));
        
        //Base condition
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i == 0){
                    dp[i][j] == false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
        
    }


int main()
{
    vector<int>arr = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    if (isSubsetSum(arr, sum) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}