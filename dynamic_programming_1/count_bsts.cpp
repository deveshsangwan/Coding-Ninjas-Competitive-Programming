/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/
#define mod 1000000007
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
      // DP to store the number of unique BST with key i 
    long long dp[n + 1]; 
    fill_n(dp, n + 1, 0); 
   
    dp[0] = 1; 
    dp[1] = 1; 
  
    for (int i = 2; i <= n; i++){ 
        for (int j = 1; j <= i; j++){ 
  
            dp[i] = (dp[i] + ((dp[i - j])%mod * (dp[j - 1])%mod))%mod; 
             //dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
        } 
    } 
  
    return dp[n];  
}