////  TOP SORT ?

#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
using namespace std;

const ll N = 110;
vector<ll>g[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,e; cin >> n >> e;
    ll indegre[n+10] = {0};
    while(e--) {
        ll u,v; cin >> u >> v;
        indegre[v]++;
        g[u].push_back(v);
    }
    vector<ll>in_zero;
    for(ll i=1 ; i<=n ; i++) {
        if(indegre[i]==0) {
            vis[i] = true;
            in_zero.push_back(i);
        }
    }

    if(in_zero.size()==0) {
        cout << -1 << endl;
    }
    else {
        vector<ll>ans;
        while(ans.size()<n) {
            ll u = in_zero.back();
            ans.push_back(u);
            in_zero.pop_back();
            for(auto &v : g[u]) {
                if(!vis[v]) {
                    indegre[v]--;
                    if(indegre[v]==0) {
                        in_zero.push_back(v);
                        vis[v] = true;
                    }
                }
            }
        }
        for(ll i=0 ; i<ans.size() ; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    for(ll k=1 ; k<=N ; k++) {
        vis[k] = false;
        g[k].clear();
    }

    return 0;
}
