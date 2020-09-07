/*
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2 
*/
#include <bits/stdc++.h>
using namespace std;
int sb(int n_2,int k,int a[],int count,int i,int** dp){
    if(n_2==0&&count==0){
        return 1;
    }
    if(n_2==0&&count!=0){
        return 0;
    }
    if(count<0){
        return 0;
    }
    if(dp[n_2][count]>-1){
        return dp[n_2][count];
    }
    if(a[0]==i+1&&k>0){
        dp[n_2][count]=sb(n_2-1,k-1,a+1,count+1,i+1,dp);
        return dp[n_2][count];
    }else{
        dp[n_2][count]=sb(n_2-1,k,a,count+1,i+1,dp)+sb(n_2-1,k,a,count-1,i+1,dp);
        return dp[n_2][count];
    }
}
int main()
{
    int d;
    cin>>d;
    for(int j=0;j<d;j++){
        int n,k;
        cin>>n>>k;
        int a[k];
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        sort(a,a+k);
        int** dp=new int*[2*n+1];
        for(int k=0;k<=2*n;k++){
            dp[k]=new int[2*n+1];
            for(int h=0;h<=2*n;h++){
                dp[k][h]=-1;
            }
        }
        cout<<sb(2*n,k,a,0,0,dp)<<endl;
    }
        return 0;
}