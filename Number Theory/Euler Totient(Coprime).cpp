// Euler Totient ----> Coprime
//     Euler Totient Function(pi)
//     pi(n) = ? it's mean, Number of pair which gcd is 1 or gcd(1 to n , n) == 1
//     if x is a prime number then pi(x) = x-1
//     if e is exponent of prime p then pi(p^e) = (p^e) - (p^e-1)
//     after derivation
//     pi(n) = n*( (p1-1)/p1  * (p2-1)/p2  * ....)
//
//     Q1.how many pair has gcd of 1, till n...mean amount of gcd(1 to n,n)==1
//     Ans = pi(n)
//     Q2.how many pair has gcd of x, till n...mean amount of gcd(1 to n,n)==x
//     Ans = pi(n/x)
//     Q3.print the sum of gcd (1 to n,n)
//     Ans : Let a,b,c be the divisors of n then the sum will be = a*(pi(n/a)) + b*(pi(n/b)) + c*(pi(n/c))

const ll N = 5e6+7;
ll coprime[N+7];
bool vis[N+7];
void COPRIME() {

    for(ll i=2 ; i<=N ; i++)
    {
        coprime[i] = i;
    }
    for(ll i=2 ; i<=N ; i++)
    {
        if(!vis[i])
        {
            for(ll j=i ; j<=N ; j+=i)
            {
                coprime[j] = (coprime[j]/i)*(i-1);
                vis[j] = true;
            }
        }
    }
}

/*
Given an array. find the number of pair which GCD is X
*/
const ll N = 1e5;
ll n,arr[N+7];
ll multiple[N+7],possible_pair[N+7];
void gcd_x() {
    map<ll,ll>mapx;
    for(ll i=1 ; i<=n ; i++) {
        mapx[arr[i]]++;
    }

    for(ll i=1 ; i<=N ; i++) {
        for(ll j=i ; j<=N ; j+=i) {
            multiple[i] += mapx[j];
        }
    }

    for(ll i=1 ; i<=N ; i++) {
        ll x = multiple[i];
        possible_pair[i] = (x*(x-1))/2;
    }
    for(ll i=N ; i>=1 ; i--) {
        for(ll j=i*2 ; j<=N ; j+=i) {
            possible_pair[i] -= possible_pair[j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }
    gcd_x();
    ll x; cin >> x;
    cout << possible_pair[x];

    return 0;
}
