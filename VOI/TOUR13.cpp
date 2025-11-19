#include <bits/stdc++.h>
/** -----CAM THUAT----- **/
// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,fma")
using namespace std;

/** -----BASIC MACROES----- **/
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define sqr(x) ((x) * (x))
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back

/** -----BIT CONTROLS----- **/
template <class T>
int getbit(T s, int i) { return (s >> i) & 1; }
template <class T>
T onbit(T s, int i) { return s | (T(1) << i); }
template <class T>
T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T>
int cntbit(T s) { return __builtin_popcount(s); }

/** -----I/O FILE----- **/
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define file_trau(name)                    \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".ans", "w", stdout); \
    }
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

/** -----CONST VALUES----- **/
const int MOD = 1e9 + 7;

/** -----EXTENSIVE FUNCTIONS----- **/
int muti(int a, int b) { return (1LL * a * b) % MOD; }
int Pow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = muti(res, x);
        x = muti(x, x);
    }
    return res;
}
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
/* Author: khoidesu */
/** -----IDEAS-----
    -------------------------- **/

/** -----GLOBAL VARIABLES----- **/
const int maxn = 1e5 + 50;
const int maxx = 1e9;
int n, m;
vector<pii> a[maxn];
/** -----COMPULSORY FUNCTIONS----- **/
bool cmp(pii a, pii b)
{
    return a.se < b.se;
}
void VarInput()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i].clear();
    while (m--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].pb({v, c});
    }
    for (int i = 1; i <= n; i++)
        sort(ALL(a[i]), cmp);
}

int d[maxn];
int dijkstra(int s)
{
    bool ok = false;
    fill(d + 1, d + n + 1, maxx);
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> p;
    p.push({0, s});
    while (!p.empty())
    {
        int kc = p.top().fi;
        int u = p.top().se;
        p.pop();
        if (u == s && d[u])
            return d[u];

        for (auto c : a[u])
        {
            int v = c.fi;
            int w = c.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                p.push({d[v], v});
            }
        }
        if (u == s && !ok)
        {
            d[u] = maxx;
            ok = true;
        }
    }
    return -1;
}
void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        int ans = dijkstra(i);
        cout << ((ans == maxx) ? -1 : ans) << endl;
    }
}

/** -----MAIN FUNCTION----- **/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file("TOUR13");
    // file_trau("contest");
    // fileTHHB;
    // auto TIME1 = chrono::steady_clock::now();
    int T = 1;
    cin >> T;
    while (T--)
    {
        VarInput();
        Solve();
    }
    // auto TIME2 = chrono::steady_clock::now();
    // auto DIFF = TIME2 - TIME1;
    // cout << "\n\nTime: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s.";
    return 0;
}
