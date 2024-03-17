////////////	== >  Standard Binary Search ?  <==
ll L=1 , R = n, ans;
while(L<=R) {
    ll mid = (L+R)/2;
    if(arr[mid]<=need) {
        ans = arr[mid];
        L = mid+1;
    }
    else {
        R = mid-1;
    }
}
