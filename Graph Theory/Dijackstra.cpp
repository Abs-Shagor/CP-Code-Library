////  dijackstra ?

#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
#define ff first 
#define ss second 
using namespace std;

const ll N = 1e5+7;

vector<pair<ll,ll>>g[N];
vector<ll>distancee(N,1e18);
ll vis[N], parent[N];

void djk(ll src) {

    set<pair<ll,ll>>sat;
    sat.insert({0,src});
    distancee[src] = 0;
    parent[1] = -1;

    while(sat.size()>0) {
        auto pr = *sat.begin();
        ll u_wt = pr.ff;
        ll u = pr.ss;
        sat.erase(sat.begin());

        if(vis[u]) continue;

        vis[u] = true;
        for(auto &p : g[u]) {
            ll v = p.ff;
            ll v_wt = p.ss;
            if(distancee[u]+v_wt<distancee[v]) {
                distancee[v] = distancee[u]+v_wt;
                sat.insert({distancee[u]+v_wt,v});
                parent[v] = u;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll tc; cin >> tc;
    while(tc--) {
        ll n,e,start,endx;
        cin >> n >> e >> start >> endx;
        while(e--) {
            ll u,v,wt;
            cin >> u >> v >> wt;
            g[u].push_back(make_pair(v,wt));
            g[v].push_back(make_pair(u,wt));
        }
        djk(min(start,endx));
        if(distancee[max(start,endx)]==1e18) {
            cout << "unreachable" << endl;
        }
        else {
            cout << distancee[max(start,endx)] << endl;
        }

        for(ll i=0 ; i<N ; i++) {
            g[i].clear();
            vis[i] = false;
            parent[i] = 0;
            distancee[i] = 1e18;
        }

    }
}
