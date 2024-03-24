////////////////		 ==>  Hashing Part  ?  <==
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll N = 4e5 + 9;
const ll p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;

ll power(ll n, ll k, ll mod) {
    ll ans = 1 % mod; n %= mod; if(n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}

ll ip1, ip2;
pair<ll,ll> pw[N], ipw[N];
void prec() {
    pw[0] =  {1, 1};
    for(ll i=1 ; i<N ; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] =  {1, 1};
    for (ll i=1 ; i<N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<ll,ll> pref[N];
void build(string s) {
    ll n = s.size();
    for (ll i=0 ; i<n ; i++) {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}
pair<ll,ll> get_substring_hash(ll i, ll j) {
    assert(i <= j);
    pair<ll,ll> hs({0, 0});
    hs.first = pref[j].first;
    if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    //Here,we can return a single value(hs.ff*mod2+hs.ss) or a pair
    return hs;
}
ll lcp(ll i, ll j, ll x, ll y) { // O(log n)
    ll l = 1, r = min(j - i + 1, y - x + 1), ans = 0;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(get_substring_hash(i, i + mid - 1)==get_substring_hash(x, x + mid - 1)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
    // lcp return the length of longest common prefix of 2 string
}
ll compare(const string &str, ll i, ll j, ll x, ll y) { // O(log n)
  ll lc = lcp(i, j, x, y); 
  ll len1 = j - i + 1, len2 = y - x + 1;
  if (len1 == len2 and lc == len1) return 0; // 0=equal
  else if (lc == len1) return -1; // -1 = 1st one small
  else if (lc == len2) return 1;
  else return (str[i + lc] < str[x + lc] ? -1 : 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // prec();

    // string str; cin >> str;
    // build(str);
    // lcp(1st_sub_string_start,1st_sub_string_end,2nd_sub_start,2nd_sub_string_end);
    // compare(str,1st_sub_string_start,1st_sub_string_end,2nd_sub_start,2nd_sub_string_end)


    
    // ll n; cin >> n;
    // string str; cin >> str;
        
    // string strx = str;
    // reverse(strx.begin(),strx.end());
    // str += strx;
    // build(str);
    // // L, R   (1 based index)
    // ll L,R; cin >> L >> R;
    // if(get_substring_hash(L-1,R-1)==get_substring_hash(2*n-R,2*n-L)) {
    //     cout << "Palindrome" << "\n";
    // }
    // else {
    //     cout << "Not a Palindrome" << "\n";
    // }

    return 0;
}

/*

//// For Learning purpose(Basic)
const ll N = 1e5 + 9;
const ll p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;

ll pw1[N], pw2[N];
void prec() {
    pw1[0] = 1;
    for (ll i=1 ; i<N ; i++) {
        pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
    }
    pw2[0] = 1;
    for (ll i=1 ; i<N ; i++) {
        pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    }
}
ll get_hash(string str) {
    ll n = str.size();
    ll hs1 = 0;
    for (ll i=0 ; i<n ; i++) {
        hs1 += 1LL * str[i] * pw1[i] % mod1;
        hs1 %= mod1;
    }
    ll hs2 = 0;
    for (ll i = 0; i < n; i++) {
        hs2 += 1LL * str[i] * pw2[i] % mod2;
        hs2 %= mod2;
    }
    //Here,we can return a single value(hs1*mod2+hs2) or a pair
    return hs1*mod2+hs2;
    //return {hs1, hs2};
}

*/
