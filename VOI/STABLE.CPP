#include <bits/stdc++.h>
/** -----CAM THUAT----- **/
// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,fma")
using namespace std;

/** -----BASIC MACROES----- **/
#define int long long
#define ull unsigned long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define fill(a, value, n) fill(a + 1, a + n + 1, value)
#define sqr(x) ((x) * (x))
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
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
#define file(name, dot)                     \
    if (fopen(name ".inp", "r"))            \
    {                                       \
        freopen(name ".inp", "r", stdin);   \
        freopen(name "." dot, "w", stdout); \
    }                                       \
    else if (fopen("input.txt", "r"))       \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }

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
/* Author: khoidesu */
/** -----IDEAS-----
    -------------------------- **/

/** -----GLOBAL VARIABLES----- **/
const int maxn = 1e5 + 50;
const int cs = 5e3 + 50;
const int INF = 1e18;
int n, m, s;
vector<int> a[maxn];
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
    set<pii> diff;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!diff.count({u, v}))
            a[u].pb(v), diff.insert({u, v});
    }
}

int d[maxn];
int c[maxn];

void dijkstra(int s)
{
    fill(d, INF, n);
    priority_queue<pii, vector<pii>, greater<pii>> p;
    p.push({0, s});
    d[s] = 0;
    c[s] = 1;

    while (!p.empty())
    {
        int u = p.top().se;
        int kc = p.top().fi;
        p.pop();

        if (kc > d[u])
            continue;

        for (auto v : a[u])
        {
            if (d[v] < d[u] + 1)
                continue;
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                c[v] = c[u];
                p.push({d[v], v});
            }
            else if (d[v] == d[u] + 1)
            {
                c[v] += c[u];
            }
        }
    }
}
void Solve()
{
    dijkstra(s);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (c[i] >= 2 && d[i] <= INF)
            cnt++;
    cout << cnt;
}

/** -----MAIN FUNCTION----- **/
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file("STABLE", "out");
    auto TIME1 = chrono::steady_clock::now();
    int T = 1;
    // cin >> T;
    while (T--)
    {
        VarInput();
        Solve();
    }
    auto TIME2 = chrono::steady_clock::now();
    auto DIFF = TIME2 - TIME1;
    cerr << "Time: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s";
    return 0;
}