#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if(n <= 0){
        return 0;
    }
    
    int a = maxMoneyLooted(arr+2,n-2)+arr[0];
    int b = maxMoneyLooted(arr+1,n-1);
    
    return max(a,b);
    
    
    /*
    //DP APPROACH
    int * dp = new int[n];
    dp[0] = arr[0];
    dp[1] = max(dp[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max((arr[i]+dp[i-2]), dp[i-1]);
    }
    return dp[n-1];
    */
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}