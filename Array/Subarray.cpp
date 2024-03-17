// all continues subarray range generation
// 0_base index| e.x. n = 3 => (0,0) (1,1) (2,2) (0,1) (1,2) (0,2)
// call: subs(0,0)  as we consider 0_base indexing
const ll N = 3;
vector<pair<ll,ll>>vp;
void subs(ll start, ll end) {
    if (end == N) {
        return;
    }
    else if (start > end) {
        subs( 0, end + 1);
    }
    else {
        vp.push_back({start,end});
        subs( start + 1, end);
    }
    return;
}
