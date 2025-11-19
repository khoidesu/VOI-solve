#include <bits/stdc++.h>
#ifdef LOCAL
#include<cpp-dump/cpp-dump.hpp>
#define debug(...) cpp_dump(__VA_ARGS__)
CPP_DUMP_SET_OPTION_GLOBAL(max_line_width, 100);
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cpp_dump::log_label::filename());
CPP_DUMP_SET_OPTION_GLOBAL(enable_asterisk, true);
#else
#define debug(...)
#endif // LOCAL
using namespace std;
#define debug cpp_dump
#define ll long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

template <class T> int getbit(T s, int i) { return (s >> i) & 1; }
template <class T> T onbit(T s, int i) { return s  (T(1) << i); }
template <class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T> int cntbit(T s) { return __builtin_popcount(s); }

const int MOD = 1e9 + 7;
bool minimize(ll &x, const ll &y) {if (x > y) {x = y; return true;} else return false;}
bool maximize(ll &x, const ll &y) {if (x < y) {x = y; return true;} else return false;}
const int maxn = 2e5 + 50;
const int cs = 5e3 + 50;
const int INF = 1e9;
int n, m, q;
ll a[cs][cs];
ll d[cs][cs];
/** -----EXTENSIVE FUNCTIONS----- **/

ll sum_rectangle(int x, int y, int u, int v){
    return d[u][v] - d[x-1][v] - d[u][y-1] + d[x-1][y-1];
}

/* (sum - x) - x = cl
    sum - 2x = cl
    cl = sum - 2*check
*/

void Solve() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + a[i][j];
    while(q--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        ll sum = sum_rectangle(x, y, u, v);

        // ngang
        ll min_ngang = sum;
        int l = x;
        int r = u;

        while(l <= r){
            int mid = l + r >> 1;
            ll check = 2 * sum_rectangle(x, y, mid, v) - sum;
            if (check >= 0) {
                minimize(min_ngang, check);
                r = mid - 1;
            }
            else {
                minimize(min_ngang, -check);
                l = mid + 1;
            }
        }

        // doc
        ll min_doc = sum;
        l = y;
        r = v;
         while(l <= r){
            int mid = l + r >> 1;
            ll check = 2 * sum_rectangle(x, y, u, mid) - sum;
            if (check >= 0) {
                minimize(min_doc, check);
                r = mid - 1;
            }
            else {
                minimize(min_doc, -check);
                l = mid + 1;
            }
        }
        cout << min(min_ngang, min_doc) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define name "TASK"
    if (fopen(name ".inp", "r")) {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    auto TIME1 = chrono::steady_clock::now();
    int T = 1;
    // cin >> T;
    while (T--)
        Solve();
    auto TIME2 = chrono::steady_clock::now();
    auto DIFF = TIME2 - TIME1;
    cerr << "Time: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s";
    return 0;
}
