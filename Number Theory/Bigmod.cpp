ll power(ll a, ll b){ //(a^b) = ? -> use this instead of inbuilt c++ pow
    if(b==0) return 1;

    ll x=power(a, b/2);
    x=(x*x);
    if(b%2==1) x=(x*a);
    return x;
}

////////////	== >  Bigmod ?  <==
 ->  (a^b)%m = bigmod(a,b,m)
 -> (a^b^c)%m = bigmod(a , bigmod(b,c,m-1) , m)
 -> (a^b^c^d)%m = bigmod(a , bigmod(b , bigmod(c,d,m-2) , m-1) , m)

ll mul_mod(ll a,ll b,ll m) { // (a*b)%m = ?
    ll ans = 0ll;
    while(b) {
        if(b & 1) {
            ans = (ans+a)%m;
            b--;
        }
        else {
            a = (a+a)%m;
            b /= 2;
        }
    }
    return ans;
}

ll pow_mod(ll a,ll b,ll m) { // (a^b)%m = ?
    ll ans = 1ll;
    while(b) {
        if(b & 1) {
            ans = mul_mod(ans,a,m);
            b--;
        }
        else {
            a = mul_mod(a,a,m);
            b /= 2;
        }
    }
    return ans;
}
ll inverse_mod(ll a,ll b,ll m) { // (a/b)%m = ?
    ll x = pow_mod(b,m-2,m);	 // as, ((a/b)%m = (a%m)*(b^-1 %m))%m
    return mul_mod(a,x,m);       // and (b^-1)%m = pow(b,m-2,m) 
}
