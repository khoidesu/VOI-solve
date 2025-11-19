#include <bits/stdc++.h>
using namespace std;
#define name "PAIR"
#define endl '\n'
#define Alisa signed main(void)
#define int long long
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()

bool minimize(int &x, const int &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
bool maximize(int &x, const int &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

const int N = 2e5 + 69;
int n, d;
vector<int> val;

namespace zero
{
    vector<pii> a;
    void solve()
    {
        sort(all(val));
        for (int i = 0; i < n; i++)
        {
            if (a.size() == 0 || val[i] > a[a.size() - 1].fi)
            {
                a.pb({val[i], 1});
            }
            else
                a[a.size() - 1].se++;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                mp[a[i].fi + a[j].fi] += min(a[i].se, a[j].se);
            }
            mp[a[i].fi + a[i].fi] += a[i].se / 2;
        }
        int res = 0;
        for (auto it : mp)
        {
            int sum = it.fi, cnt = it.se;
            maximize(res, cnt);
        }
        cout << res;
    }
}

namespace one
{
    vector<piii> p;
    bool vis[N];
    bool cmp(piii a, piii b)
    {
        if (a.fi != b.fi)
            return a.fi < b.fi;
        if (a.se.fi < b.se.fi)
            return a.se.fi < b.se.fi;
        return a.se.se > b.se.se;
    }
    void solve()
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                p.pb({val[i] + val[j], {i, j}});
            }
        sort(all(p), cmp);
        int cnt = 0;
        n = p.size();
        for (int i = 0; i < n - 1; i++)
        {
            int tmp = 1;
            memset(vis, 0, sizeof vis);
            vis[p[i].se.fi] = 1;
            vis[p[i].se.se] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (p[j].fi - p[i].fi <= d)
                {
                    if (!vis[p[j].se.fi] && !vis[p[j].se.se])
                    {
                        vis[p[j].se.fi] = 1;
                        vis[p[j].se.se] = 1;

                        tmp++;
                    }
                }
                else
                    break;
            }
            maximize(cnt, tmp);
        }
        cout << cnt;
    }
}
void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        val.pb(x);
    }
    if (d == 0)
        return zero::solve();
    if (d == 1)
        return one::solve();
}

Alisa
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name ".inp", "r", stdin);
    freopen(name ".out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    // cerr << "Time : " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
