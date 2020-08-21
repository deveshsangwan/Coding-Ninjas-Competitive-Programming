/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/
#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    int dp[n];
    dp[0] = arr[0];
    dp[1] = arr[1];
    for(int i = 2; i < n; i++){
        dp[i] = arr[i] + max(dp[i - 2], dp[i - 3]);
    }
    return max(dp[n - 1], dp[n - 2]);
}
