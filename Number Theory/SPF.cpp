//spf
const ll N = 1e7+9;
ll spf[N+7];
void SPF() {	
    for (ll i = 2; i < N; i++) {
        if(!spf[i]) {
            for (ll j = i; j < N; j += i) {
                if(!spf[j]) {
                    spf[j] = i;
                }
            }
        }
    }
}
