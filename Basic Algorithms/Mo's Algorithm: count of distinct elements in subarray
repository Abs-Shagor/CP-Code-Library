#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
using namespace std;

struct node {
    // a = L,  b = R,  c = answer,  d = queries_index
    ll a,b,c,d;
};
const ll block = 555;
bool cmp(node &x, node &y) {
    if((x.a/block) != (y.a/block)) {
        return (x.a/block)<(y.a/block);
    }
    else {
        return (x.b<y.b);
    }
}
bool cmpx(node &x, node &y) {
    return x.d<y.d;
}
ll mapx[1000007];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll arr[n+7];
    for(ll i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }

    vector<node> vpp;
    ll q; cin >> q;
    for(ll i=0 ; i<q ; i++) {
        ll L,R; cin  >> L >> R;
        vpp.push_back({L,R,0LL,i});
    }
    sort(vpp.begin(),vpp.end(),cmp);
    
    // initially
    set<ll>sat;
    ll L = vpp[0].a, R = vpp[0].b;
    for(ll i=L ; i<=R ; i++) {
        sat.insert(arr[i]);
        mapx[arr[i]]++;
    }
    ll ans = sat.size();
    vpp[0].c = ans;
    for(ll i=1 ; i<q ; i++) {
        ll new_L = vpp[i].a, new_R = vpp[i].b;

        // first extend the range
        while(L>new_L) {
            --L;
            mapx[arr[L]]++;
            if(mapx[arr[L]]==1) ++ans;
        }
        while(R<new_R) {
            ++R;
            mapx[arr[R]]++;
            if(mapx[arr[R]]==1) ++ans;
        }

        // then reduce it
        while(L<new_L) {
            mapx[arr[L]]--;
            if(mapx[arr[L]]<=0) --ans;
            ++L;
        }
        while(R>new_R) {
            mapx[arr[R]]--;
            if(mapx[arr[R]]<=0) --ans;
            --R;
        }
        vpp[i].c = ans;
    }

    sort(vpp.begin(),vpp.end(),cmpx);
    for(ll i=0 ; i<q ; i++) {
        cout << vpp[i].c << "\n";
    }

    return 0;
}
