double L = 0, R = n, ans;
while(L<=R) {
    double mid = (L+R)/2;
    if(ok(mid)) {
        ans = mid;
        R = mid-0.0000001; // increase or decrease according to 
    }                      // set precision given in question
    else {
        L = mid+0.0000001;
    }
}
cout << fixed << setprecision(6) << ans << endl;
