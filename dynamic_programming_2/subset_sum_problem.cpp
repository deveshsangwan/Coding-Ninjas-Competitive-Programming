/*
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/
#include <bits/stdc++.h>
using namespace std;

bool SubsetSum(int n, int *arr, int k){
    bool** dp = new bool*[2];
	for(int i = 0; i <= 1; i++){
		dp[i] = new bool[k + 1];
	}
    
    for(int i = 0; i <= k; i++){
        dp[0][i] = false;
    }
    dp[0][0] = true;

	int flag = 1;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){

			dp[flag][j] = dp[flag^1][j];

			if(j >= arr[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j - arr[i - 1]];
			}
		}
		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][k];
	return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    if(SubsetSum(n, arr, k)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
