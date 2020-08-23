/*
Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
A subsequence of a string S whose length is K, is a string containing characters in same relative order as they are present in S, 
but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K. 
For example, subsequences of string "abc" are -- ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
Line 1: String S1
Line 2: String s2
Output Format :
Length of the longest common subsequence.
Constraints :
1 <= M <= 100
1 <= N <= 100

Time Limit: 1 sec
Sample Input 1:
adebc
dcadb
Sample Output 1:
3
Explanation of Sample Input 1:
"a", "d", "b", "c", "ad", "ab", "db", "dc" and "adb" are present as a subsequence in both the strings in which "adb" has the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
Sample Input 2:
abcd
acbdef
Sample Output 2:
3
Explanation of Sample Input 2:
"a", "b", "c", "d", "ab", "ac", "ad", "bd", "cd", "abd" and "acd" are present as a subsequence in both the strings S1 and S2 in which "abd" and "acd" are of the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
*/
#include<iostream>
#include<cstring>
using namespace std;
int lcs(string s, string t){ 
    int m = s.size(); 
    int n = t.size(); 
    int **ans = new int*[m+1]; 
    for(int i = 0; i <= m; i++) { 
        ans[i] = new int[n+1]; 
    }  
    for(int j = 0; j <= n; j++) { 
        ans[0][j] = 0; 
    } 
    for(int i = 0; i <= m; i++) { 
        ans[i][0] = 0; 
    } 
    for(int i = 1; i <= m; i++) { 
        for(int j = 1; j <= n; j++) { 
            if(s[m-i] == t[n-j]) { 
                ans[i][j] = 1 + ans[i-1][j-1]; 
            } 
            else { 
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]); 
            } 
        } 
    } 
    return ans[m][n]; 
}