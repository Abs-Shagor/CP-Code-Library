//// all subset using bruteforce recursion n<=22
ll n;
ll arr[30];
vector<vector<ll>>all_subset;
void mv(vector<ll>&subset,ll i) {
    if(i==n+1) {
        all_subset.push_back(subset);
        return;
    }
    mv(subset,i+1); // without a[i]

    // with a[i]
    subset.push_back(arr[i]);
    mv(subset,i+1);
    subset.pop_back();
}

//// all subset using bitmask 
    ll n = 3;
    ll arr[n+9];
    for(ll i=1 ; i<=n ; i++) {
        arr[i] = i;
    }
    for(ll i=0 ; i<(1<<n) ; i++) { //as,there can be 2^n subset of size n
        for(ll j=0 ; j<n; j++) { // as we represent the whole array as bit
            if(i&(1<<j)) {		 // if we look at the bit from 0 to (2^n)-1
                cout << arr[j+1] << " "; //we can see that actually they the
            } // bit representation are the subset of size n 
        }
        cout << endl;
    }
