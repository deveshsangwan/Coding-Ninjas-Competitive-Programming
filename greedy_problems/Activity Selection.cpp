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