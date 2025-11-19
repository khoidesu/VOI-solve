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
const int maxn = 2e5 + 50;
const int cs = 2e4 + 50;
const int INF = 1e18;
int n;
int a[10][cs];
int dp[cs][20];
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
    cin >> n;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
}

bool issub()
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] > 0)
                return true;
    return false;
}

void special()
{
    int res = -INF;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            maximize(res, a[i][j]);
    cout << res;
}

void Solve()
{
    int res = -INF;

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < 16; k++)
        {
            dp[i][k] = -INF;
            bool ok = true;
            for (int t = 0; t < 3; t++)
                if ((getbit(k, t) & getbit(k, t + 1)) == 1)
                {
                    ok = false;
                    break;
                }

            if (!ok)
                continue;

            int s = 0;
            for (int t = 0; t < 4; t++)
                if (getbit(k, t) == 1)
                    s += a[t + 1][i];

            for (int t = 0; t < 16; t++)
            {
                if ((t & k) == 0)
                    dp[i][k] = max(dp[i][k], dp[i - 1][t] + s);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 16; j++)
            maximize(res, dp[i][j]);

    if (!issub())
        special();
    else
        cout << res;
}

/** -----MAIN FUNCTION----- **/
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file("TASK", "out");
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