#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll power(ll x,ll y,ll m=1e9+7){ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

const int N = 30000 + 10;
vector<pair<int, int>> g[N];
bool vis[N];
int mx, f_node;

void dfs(int node, int dist)
{
    vis[node] = 1;
    if(dist > mx)
    {
        mx = dist;
        f_node = node;
    }
    for(auto [child, w] : g[node])
    {
        if(vis[child]) continue;
        dfs(child, dist + w);
    }
}

void solve()
{
    int n;
    cin >> n;

    for(int i = 0; i <= n; ++i)
    {
        g[i].clear();
        vis[i] = false;
    }

    for(int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }

    memset(vis, 0, sizeof(vis));
    mx = 1;
    dfs(1, 0);

    memset(vis, 0, sizeof(vis));
    mx = 1;
    dfs(f_node, 0);

    cout << mx << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        cout<<"Case "<<TC<<": ";
        solve();
    }
}