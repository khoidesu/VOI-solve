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
const ll maxn = 1e5 + 500;
const ll maxx = 1e18;
ll n, m;
struct edges
{
    /* edges */
    ll u, v, w;
};
vector<edges> a;
vector<pll> g[maxn];
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        edges e;
        cin >> e.u >> e.v >> e.w;
        a.pb(e);
    }
}
/*------------------MST----------------------*/
ll par[maxn], sz[maxn];
void make_set()
{
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
}
ll find(ll v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}
bool Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    return true;
}
bool cmp(edges a, edges b)
{
    return a.w > b.w;
}
void kruskal()
{
    sort(ALL(a), cmp);

    ll d = 0;
    for (int i = 0; i < m; i++)
    {
        if (d == n - 1)
            break;
        edges e = a[i];
        if (Union(e.u, e.v))
        {
            g[e.u].pb({e.v, e.w});
            g[e.v].pb({e.u, e.w});
        }
    }
}

/*------------------LCA----------------------*/
struct Data
{
    ll par, minc = maxx;
};
ll h[maxn];
Data up[maxn][21];
bool visited[maxn];

void dfs(int u, int p)
{
    for (auto it : g[u])
    {
        int v, c;
        v = it.first, c = it.second;
        visited[v] = true;
        if (v == p)
            continue;
        h[v] = h[u] + 1;
        up[v][0].par = u;
        up[v][0].minc = c;
        for (int lg = 1; lg <= 19; lg++)
        {
            up[v][lg].par = up[up[v][lg - 1].par][lg - 1].par;
            up[v][lg].minc = min(up[v][lg - 1].minc, up[up[v][lg - 1].par][lg - 1].minc);
        }
        dfs(v, u);
    }
}

ll get(ll u, ll v)
{
    Data res;
    // mặc định u có độ sâu lớn hơn v
    if (h[u] < h[v])
        swap(u, v);
    ll depth = h[u] - h[v];
    // từ u nhảy lên cha có cùng độ sâu với v đồng thời cập nhật max, min các cạnh
    for (int i = 20; i >= 0; i--)
    {
        if (getbit(depth, i))
        {
            res.minc = min(res.minc, up[u][i].minc);
            u = up[u][i].par;
        }
    }

    // u bằng v thì in ra kết quả
    if (u == v)
    {
        return res.minc;
    }
    // u và v nhảy đồng thời lên cha chung gần nhất và cập nhật
    for (int i = 20; i >= 0; --i)
    {
        if (up[u][i].par != up[v][i].par)
        {
            res.minc = min({res.minc, up[u][i].minc, up[v][i].minc});
            u = up[u][i].par;
            v = up[v][i].par;
        }
    }
    res.minc = min({res.minc, up[u][0].minc, up[v][0].minc});
    return res.minc;
}
void buildLCA()
{
    h[1] = 1;
    dfs(1, 1);
}

void Solve()
{
    make_set();
    kruskal(); // tao cay khung lon nhat

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto c : g[i])
    //         cout << c.fi << " (" << c.se << ") ";
    //     cout << endl;
    // }

    buildLCA();

    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        edges e = a[i];
        if (!Union(e.u, e.v))
        {
            ll tmp = get(e.u, e.v);
            // cout << tmp << endl;
            ans += max((ll)0, tmp - e.w);
        }
    }
    cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file("upgranet");
    // file_trau("contest");
    // fileTHHB;
    // auto TIME1 = chrono::steady_clock::now();
    int T = 1;
    // cin >> T;
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
