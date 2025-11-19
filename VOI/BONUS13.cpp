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
const int maxn = 1e2 + 50;
const int maxx = 1e9;
int n;
int a[maxn][maxn];
vector<pii> yes, no;
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u = 8 - u + 1;
        a[u][v] = c;
    }
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            if (a[i][j] > 0)
                yes.pb({i, j});
            else
                no.pb({i, j});
}
bool ishau(int x, int y, int u, int v)
{
    if (x == u || y == v)
        return true;
    if (x - y == u - v)
        return true;
    if (x + y == u + v)
        return true;
    return false;
}
bool isxe(int x, int y, int u, int v)
{
    if (x == u || y == v)
        return true;
    return false;
}
bool istuong(int x, int y, int u, int v)
{
    if (x - y == u - v)
        return true;
    if (x + y == u + v)
        return true;
    return false;
}
bool isma(int x, int y, int u, int v)
{
    if (abs(x - u) == 1 && abs(y - v) == 2)
        return true;
    if (abs(x - u) == 2 && abs(y - v) == 1)
        return true;
    return false;
}
void Solve()
{
    ll res = 0;
    n = no.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                        for (int t = 0; t < n; t++)
                        {
                            if (t != i && t != j && t != k)
                            {
                                ll tmp = 0;
                                pii hau = no[i];
                                pii xe = no[j];
                                pii tuong = no[k];
                                pii ma = no[t];

                                for (auto [c, v] : yes)
                                {
                                    if ((ishau(hau.fi, hau.se, c, v)) || (isxe(xe.fi, xe.se, c, v)) || (istuong(tuong.fi, tuong.se, c, v)) || (isma(ma.fi, ma.se, c, v)))
                                        tmp += a[c][v];
                                }
                                maximize(res, tmp);
                            }
                        }
                }
        }
    }
    cout << res;
}

/** -----MAIN FUNCTION----- **/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // file("contest");
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
