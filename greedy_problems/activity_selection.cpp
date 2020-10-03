/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second!=p2.second)
        return p1.second<p2.second;
    else
        return p1.first>=p2.first;
}

int main()
{
    int n=0;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        pair<int, int> p;
        
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(),cmp);
    int ans = 1;
    int last = 0;
    for(int i=1; i<n; i++){
        if(v[last].second<=v[i].first){
            last = i;
            ans++;
        }
    }
    cout << ans;
    return 0;
}