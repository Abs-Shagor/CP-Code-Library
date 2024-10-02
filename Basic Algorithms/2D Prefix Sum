//// 2d prefix sum
ll n,m; cin >> n >> m;
ll prefix[n+7][m+7];
memset(prefix,0,sizeof(prefix));
for(ll i=1 ; i<=n ; i++) {
    for(ll j=1 ; j<=m ; j++) {
        cin >> prefix[i][j];
    }
}
for(ll i=1 ; i<=n ; i++) {
    for(ll j=1 ; j<=m ; j++) {
        prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+prefix[i][j];
    }
}
cout << prefix[4][4];
