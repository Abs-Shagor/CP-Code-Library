// Problem Name: NAKANJ - Minimum Knight moves !!!
// Link : https://www.spoj.com/problems/NAKANJ/en/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define ff first
#define ss second


// ll dx[8] = { 0,  0, -1, +1, -1, -1, +1, +1};
// ll dy[8] = {-1, +1,  0,  0, -1, +1, -1, +1};

////// MINIMUM KNIGHT MOVES
ll row(string s) {
    return (s[0]-'a')+1;
}
ll colum(string s) {
    return (s[1]-'1')+1;
}
bool valid(ll x,ll y) {
    return (1<=x && x<=8 && 1<=y && y<=8 );
}
const ll N = 10;
ll vis[N][N];
ll Level[N][N];
ll dx[] = {-1,+1,+2,+2,+1,-1,-2,-2};
ll dy[] = {+2,+2,+1,-1,-2,-2,-1,+1};

ll bfs(string start,string endx) {

    ll starting_row = row(start);
    ll starting_colum = colum(start);
    ll end_row = row(endx);
    ll end_colum = colum(endx);


    queue<pair<ll,ll>>q;
    q.push({starting_row,starting_colum});
    vis[starting_row][starting_colum] = true;
    while(!q.empty()) {
        pair<ll,ll>u = q.front();
        q.pop();
        ll u_x = u.ff;
        ll u_y = u.ss;
        for(ll i=0 ; i<8; i++) {
            if(valid(u_x+dx[i],u_y+dy[i]) && !vis[u_x+dx[i]][u_y+dy[i]] ) {
                q.push({u_x+dx[i],u_y+dy[i]});
                vis[u_x+dx[i]][u_y+dy[i]] = true;
                Level[u_x+dx[i]][u_y+dy[i]] = Level[u_x][u_y]+1;
            }
        }
    }
    return (Level[end_row][end_colum]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll tc; cin >> tc;
    while(tc--) {
        string start,endx; cin >> start >> endx;

        cout << bfs(start,endx) << endl;
        for(ll i=0 ; i<=N ; i++) {
            for(ll j=0 ; j<=N ; j++) {
                vis[i][j] = false;
                Level[i][j] = 0;
            }
        }
    }
}
