#include<bits/stdc++.h>
using namespace std;
 
 
long long int dp[1 << 20];
int can[20];
int main(){
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)continue;
			if (((i + 1) & (j + 1)) == j + 1){
				can[i] |= (1 << j);
			}
		}
	}
	for (int i = 0; i < (1 << n); i++){
 
			for (int j = 0; j < n; j++){
				if ((i >> j) & 1){
 
				}
				else{
					if ((i&can[j]) == can[j]){
						dp[i | (1 << j)] += dp[i];
					}
				}
			}
	}
	cout << dp[(1 << n) - 1]<< endl;
	return 0;
}