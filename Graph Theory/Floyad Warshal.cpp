/////// FLOYAD  WARSHAL ?
#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,e,q; cin >> n >> e >> q;

    ll mattrix[n+10][n+10];
    for(ll i=1 ; i<=n ; i++) {
        for(ll j=1 ; j<=n ; j++) {
            mattrix[i][j] = 1e18;
            if(i==j) mattrix[i][j] = 0;
        }
    }
    while(e--) {
        ll u,v,wt; cin >> u >> v >> wt;
        mattrix[u][v] =min(mattrix[u][v],wt);
        mattrix[v][u] =min(mattrix[v][u],wt);
    }
    
    for(ll k=1 ; k<=n ; k++) {
        for(ll i=1 ; i<=n ; i++) {
            for(ll j=1 ; j<=n ; j++) {
                mattrix[i][j] = min( mattrix[i][j] ,mattrix[i][k]+mattrix[k][j]);
            }
        }
    }
    
     while(q--) {
        ll st,en; cin >> st >> en;

        if(mattrix[st][en]==1e18) {
            cout << -1 << endl;
        }
        else {
            cout << mattrix[st][en] << endl;
        }
    }
    
    return 0;
}
