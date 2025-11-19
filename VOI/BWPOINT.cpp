/// Copyright © 2023 Khoidesu. All Rights Reserved
/// https://khoidesu.github.io/
//----------------------------------LIBRARY----------------------------------
#include <bits/stdc++.h>
using namespace std;
//----------------------------------DEFINE----------------------------------
#define ll long long
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
ll n;
pair<ll, ll> a[200001];

//----------------------------------o0 END 0o----------------------------------
// 0: trang
// 1: den
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll tmp;
        cin >> tmp;
        a[i].first = tmp;
        a[i].second = 1;
    }
    ll NewN = n * 2;
    for (int i = n + 1; i <= NewN; i++)
    {
        ll tmp;
        cin >> tmp;
        a[i].first = tmp;
        a[i].second = 0;
    }
    sort(a + 1, a + NewN + 1);
    ll cnt = 0;
    for (int i = 2; i <= NewN; i++)
    {
        if ((a[i - 1].second != a[i].second) && (a[i].second != -1 && a[i - 1].second != -1))
        {
            cnt++;
            a[i].second = a[i - 1].second = -1;
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
