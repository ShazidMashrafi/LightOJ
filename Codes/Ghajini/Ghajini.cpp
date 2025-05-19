#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll power(ll x,ll y,ll m=1e9+7){ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n, d;
    cin >> n >> d;
    deque<int> v;
    set<int> st;
    int ans = 0, mx = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(v.size() >= d)
        {
            int e = v.front();
            v.pop_front();
            st.erase(e);
        }
        v.push_back(x);
        st.insert(x); 
        mx = 0;
        if(!st.empty()) mx = *prev(st.end()) - *st.begin();
        ans = max(mx, ans);
    }
    if(!st.empty()) 
        mx = *prev(st.end()) - *st.begin();
    ans = max(mx, ans);
    cout << ans << endl;
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