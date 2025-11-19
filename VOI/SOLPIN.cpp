/**
    I have no idea
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define ll long long
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
int n, m, q;
int a[1001][1001];
int f[1001][1001];
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}
void prepare()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = m + 1; j <= 2 * m; j++)
            a[i][j] = a[i][j - m];
    }
    for (int j = 1; j <= 2 * m; j++)
    {
        for (int i = n + 1; i <= 2 * n; i++)
            a[i][j] = a[i - n][j];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = 1; j <= m * 2; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
}
void Solve()
{
    int b = 1;
    int e = 1;
    int p, x, y, u, v, s, t;
    cin >> q;
    while (q--)
    {
        cin >> p;
        if (p == 0)
        {
            cin >> x >> y;
            x %= m;
            y %= n;
            b += x;
            e += y;
            if (b > m)
                b -= m;
            if (e > n)
                e -= n;
        }
        else
        {
            cin >> u >> v >> s >> t;
            u += e - 1;
            s += e - 1;
            v += b - 1;
            t += b - 1;
            int res = f[s][t] - f[s][v - 1] - f[u - 1][t] + f[u - 1][v - 1];
            cout << res << endl;
        }
    }
}
/** -----MAIN FUNCTION----- **/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // file("contest");
    // file_trau("contest");
    //  fileTHHB;
    VarInput();
    prepare();
    // auto TIME1 = chrono::steady_clock::now();
    Solve();
    // auto TIME2 = chrono::steady_clock::now();
    // auto DIFF = TIME2 - TIME1;
    // cout << "\n\nTime: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s.";
    return 0;
}
