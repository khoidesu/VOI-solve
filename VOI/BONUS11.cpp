/// Copyright © 2023 Khoidesu. All Rights Reserved
//----------------------------------LIBRARY----------------------------------
#include <bits/stdc++.h>
using namespace std;
//----------------------------------DEFINE----------------------------------
#define ll int
#define endl '\n'
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define EACH(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(x) ((x) * (x))
//----------------------------------o0 continue 0o---------------------------

//----------------------------------DEBUG----------------------------------
#define DEBUG(x)             \
    {                        \
        cout << #x << " = "; \
        cout << (x) << endl; \
    }
#define PR(a, n)             \
    {                        \
        cout << #a << " = "; \
        FOR(_, 1, n)         \
        cout << a[_] << ' '; \
        cout << endl;        \
    }
#define PR0(a, n)            \
    {                        \
        cout << #a << " = "; \
        REP(_, n)            \
        cout << a[_] << ' '; \
        cout << endl;        \
    }
//----------------------------------o0 continue 0o---------------------------

//----------------------------------VARIABLE----------------------------------
ll n, m;
ll k;
ll a[1001][1001];
ll f[1001][1001];
//----------------------------------o0 END 0o----------------------------------

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
            // cout << f[i][j] << " ";
        }
        /// cout << endl;
    }
    ll res = -1e9;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            res = max(res, f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k]);
    cout << res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
