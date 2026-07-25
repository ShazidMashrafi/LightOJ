#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  Dpos(n) fixed << setprecision(n)
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

int fun(int i, int j, int w, int h, auto &g, auto &vis)
{
    // dbg("Hi1");
    if(g[i][j] == '#' || vis[i][j]) return 0;
    // dbg(g, vis);
    vis[i][j] = true;
    int ct = 1;
    if(i > 0) {
        // dbg("Hi2");
        ct += fun(i - 1, j, w, h, g, vis);
    }
    if(i + 1 < h) {
        ct += fun(i + 1, j, w, h, g, vis);
    }
    if(j > 0) {
        ct += fun(i, j - 1, w, h, g, vis);
    }
    if(j + 1 < w) {
        ct += fun(i, j + 1, w, h, g, vis);
    }
    // dbg(ct);
    return ct;
}

void solve()
{
    int w, h;
    cin >> w >> h;
    vector<string>g(h);
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    for(auto &s : g) {
        cin >> s;
    }
    // dbg(g);
    // dbg(vis);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(g[i][j] == '@') {
                // dbg(g[i][j], i, j);
                cout << fun(i, j, w, h, g, vis)<< endl;
            }
        }
    }
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        cout<<"Case "<<TC<<": ";
        solve();
    }
}
