/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/
#include <bits/stdc++.h>
using namespace std;

void NOofCoins(int *ans, int *l, int *r, int n, int m){
    ans[0] = l[0];
    for(int i = 1; i < n; i++){
        ans[i] = l[i] - r[i - 1] + ans[i - 1];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int l[n], r[n];
    fill(l, l + n, 0);
    fill(r, r + n, 0);
    for(int i = 0; i < m; i++){
        int st, en;
        cin >> st >> en;
        l[st - 1]++;
        r[en - 1]++;
    }
    
    
    int ans[n];
    fill(ans, ans + n, 0);
    NOofCoins(ans, l, r, n, m);
    /*for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;*/
    int arr[n];
    fill(arr, arr + n, 0);
    for(int i = 0; i < n; i++){
        arr[ans[i] - 1]++;
    }
     /*for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    
    for(int i = n - 2; i >= 0; i--){
        arr[i] += arr[i + 1];
    }
    
    
    int q;
    cin >> q;
    
    while(q--){
        int x;
        cin >> x;
        cout << arr[x - 1] << endl;
    }
    return 0;
}
