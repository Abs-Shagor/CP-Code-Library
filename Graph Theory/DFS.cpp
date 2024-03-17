#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
using namespace std;

const ll N = 1e5;
vector<ll>g[N];
bool vis[N];
void dfs(ll u) {
	vis[u] = true;
	for(auto &v : g[u]) {
		if(!vis[v]) {
			dfs(v);
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,e; cin >> n >> e;
    while(e--) {
        ll u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1);

    return 0;
}

