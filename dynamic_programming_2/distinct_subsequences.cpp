/*
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.
Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 
Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.
Sample Input
3
AAA
ABCDEFG
CODECRAFT
Sample Output
4
128
496
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
long long countSub(string str)
{
    long long m=1e9+7;
    vector<long long> last(MAX_CHAR, -1); 
  
    long long n = str.length(); 
  
    long long dp[n + 1]; 
    dp[0] = 1; 
  
    for (int i = 1; i <= n; i++)
    { 
        dp[i] = (2%m* (dp[i - 1])%m)%m; 
  
        if (last[str[i - 1]] != -1) 
            dp[i] = (dp[i]%m - dp[last[str[i - 1]]]%m)%m; 
        if(dp[i] < 0){
            dp[i] += m;
        }
   
        last[str[i - 1]] = (i - 1); 
    } 
  
    return dp[n]%m; 
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<countSub(s)<<endl;
    }
    return 0;
}