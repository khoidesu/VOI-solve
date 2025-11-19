#include <bits/stdc++.h>
#ifdef LOCAL
#include<cpp-dump/cpp-dump.hpp>
#define debug(...) cpp_dump(__VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL
using namespace std;
#define int long long
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
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
const int maxn = 2e6 + 50;
const int cs = 5e3 + 50;
const int INF = 1e18;
int n, k;
int pre[maxn];
struct Data{
    int l, r, w;
} a[maxn];
/** -----EXTENSIVE FUNCTIONS----- **/

bool cmp(Data a, Data b){
    return a.l < b.l;
}

pair<int, int> check(int val)
{
    pair<int, int> close_ = {0, 0};
    pair<int, int> open_ = {-INF, 0};
    for(int i = 0; i <= n; i++)
    {
        maximize(close_, make_pair(open_.fi+ pre[i], open_.se));
        maximize(open_, make_pair(close_.fi - pre[i] - val, close_.se - 1));

    }
    close_.se *= -1;
    return close_;
}

void Solve() {
    cin >> n;

    int s, t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }
    k = 1;
    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].w;

    int l = 0, r = 1e18, res = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;

        pair<int, int> cur = check(mid);

        if(cur.se <= k) res = cur.fi + k * mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else
    #define name "SSEQ"
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
#endif // LOCAL
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
/**************************
* Date: Monday 2024-10-28
* Author: khoidesu
            蛍♡
**************************/
