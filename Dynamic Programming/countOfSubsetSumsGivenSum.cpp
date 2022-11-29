#include <bits/stdc++.h>
using namespace std;


//Only dp code
int perfectSum(vector<int>arr, int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
         long long m = 1e9 + 7;
        //Base Case
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i == 0){
                    dp[i][j] == 0;
                }
                if(j == 0){
                    dp[i][j] = 1;
                }
            }
        }
        
        //main code
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] %m + dp[i-1][j]%m;
                }
                else{
                    dp[i][j] = dp[i-1][j]%m;
                }
            }
        }
        
        return dp[n][sum]%m;
	}
	  

int main()
{
    vector<int> arr = { 5, 10, 12, 13, 15, 18 };
    int n = 6;
    int K = 30;
    int ans = perfectSum(arr,n, K);
    cout<<ans<<endl;
    return 0;
}
 