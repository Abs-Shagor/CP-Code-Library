//DSU & MST ?
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long

const ll N = 2e5;
ll parent[N];
ll sizeof_group[N];
void make_node(ll v) {
    parent[v] = v;
    sizeof_group[v] = 1;
}
ll find_root(ll v) {
    if(parent[v]==v) return v;
    return parent[v] = find_root(parent[v]); // path compression
}
void Union(ll a,ll b) {
    a = find_root(a);
    b = find_root(b);
    if(a!=b) {
        if(sizeof_group[a]<sizeof_group[b]) swap(a,b); //union by size
        parent[b] = a;
        sizeof_group[a] += sizeof_group[b];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,e; cin >> n >> e;
    for(ll i=1 ; i<=n ; i++) {
        make_node(i);
    }
    vector<pair<ll,pair<ll,ll>>>vp;
    while(e--) {
        ll u,v,w; cin >> u >> v >> w;
        vp.push_back({w,{u,v}});
    }
    sort(vp.begin(),vp.end());
    ll ans = 0;
    map<pair<ll,ll>,ll>mapx;
    for(ll i=0 ; i<vp.size() ; i++) {
        ll wt = vp[i].ff;
        ll u = vp[i].ss.ff;
        ll v = vp[i].ss.ss;
        if(find_root(u)==find_root(v)) continue; // creating cycle or loop
        Union(u,v);
        ans += wt;
        mapx[{u,v}] = wt;
    }
    cout << "Minimun cost : " << ans << endl;
    cout << "MST will be  :" << endl;
    for(auto &v : mapx) {
        cout << v.ff.ff << " " << v.ff.ss << " " << v.ss << endl;
    }

    return 0;
}
