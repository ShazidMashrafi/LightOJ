#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define dbg(...)
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

int ct;
int n, k;
vector<bool> used;

void backtrack(string& current) {
    if (ct == k) return;

    if (current.size() == n) {
        cout << current << endl;
        ct++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            current.push_back('A' + i);
            
            backtrack(current);
            
            current.pop_back();
            used[i] = false;
        }
    }
}

void solve()
{
    cin >> n >> k;
    ct = 0;
    used.assign(n, false);
    string current = "";
    backtrack(current);
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
        cout<<"Case "<<TC<<": " << endl;
        solve();
    }
}