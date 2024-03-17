#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lc  (n << 1)
#define rc  (n << 1) + 1
#define mid ((s + e) >> 1)

const ll N = 2e5+7;
ll arr[N], t[4 * N],lazy[4 * N]; // as we know,there can be atmost (4n-1) Node

ll combine(ll a, ll b) { // ki lagbe(Answer) ?
    return (a+b);
}
void build(ll n, ll s, ll e) {
    lazy[n] = -1; // here
    if (s == e) {
        t[n] = arr[s]; // here
        return;
    }
    build(lc, s, mid);
    build(rc, mid + 1, e);
    t[n] = combine(t[lc] , t[rc]); // :)
}
void push(ll n, ll s, ll e) {
    if (lazy[n] == -1) return;

    t[n] = (e-s+1)*lazy[n]; // here (update operation)

    if (s != e) {
        lazy[lc] = lazy[n]; // here 
        lazy[rc] = lazy[n]; // here
    }
    lazy[n] = -1;
}
void update(ll n, ll s, ll e, ll l, ll r, ll x) {
    push(n, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[n] =  x; // here
        push(n, s, e);
        return;
    }
    update(lc, s, mid, l, r, x);
    update(rc, mid + 1, e, l, r, x);
    t[n] = combine(t[lc] , t[rc]); // :)
}
ll query(ll n, ll s, ll e, ll l, ll r) {
    push(n, s, e);
    if (e < l || r < s) return 0; // here 
    if (l <= s && e <= r) return t[n];
    return combine( query(lc, s, mid, l, r) , query(rc, mid + 1, e, l, r) ); // :)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,q; cin >> n >> q;
    for(ll i=1 ; i<=n ; i++) cin >> arr[i];

    build(1,1,n);
    
    while(q--) {
        ll qs; cin >> qs;
        if(qs==1) {
            ll pos,x; cin >> pos >> x;
            ++pos;
            update(1,1,n,pos,pos,x);
        }
        else {
            ll L,R; cin >> L >> R;
            ++L;
            cout << query(1,1,n,L,R) << "\n";
        }
    }

    return 0;
}
