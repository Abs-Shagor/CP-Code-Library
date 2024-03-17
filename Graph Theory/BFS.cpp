#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
using namespace std;

const ll N = 2e3+10;

vector<ll>g[N];
ll vis[N],Level[N];

void bfs(ll ux) {
    queue<ll>q;
    q.push(ux);
    vis[ux] = true;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(auto &v : g[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = true;
                Level[v] = Level[u]+1;
            }
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
    
    bfs(1);

    return 0;
}

