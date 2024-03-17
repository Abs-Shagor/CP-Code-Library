////////// 	== > Basic Sieve ? < ==  
const ll N = 1e7+7;
vector<bool>isprime(N,true);
vector<ll> primeList;
void sieve() {
    isprime[0] = isprime[1] = false;
    for(ll i=2 ; i*i<=N ; i++){
        if(isprime[i]==true){
            for(ll j=2*i ; j<=N ; j=j+i){
                isprime[j] = false;
            }
        }
    }
    for(ll i=2 ; i<=N ; i++) {
        if(isprime[i]==true) {
            primeList.push_back(i);
        }
    }
}

////////// 	== > more powerfull sieve  up to 1e8* ? < ==  
const int N = 1e8 + 9; 
const int mxprm = 6e6 + 9; //max number of primes

int p_size = 0; //size of primeList
bitset <N> vis;
int primeList[mxprm];

void sieve() {
    vis[0] = vis[1] = 1;
    primeList[p_size++] = 2;
    int lim = sqrt(N * 1.0) + 2;
    for (int i = 4; i < N; i += 2) vis[i] = 1;
    for (int i = 3; i < N; i += 2) {
        if (!vis[i]) {
            primeList[p_size++] = i;
            if (i <= lim) {
                for (int j = i * i; j < N; j += i) {
                    vis[j] = 1;
                }
            }
        }
    }
}
