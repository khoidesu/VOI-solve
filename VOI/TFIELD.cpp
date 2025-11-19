#include <bits/stdc++.h>
#define name "contest"
#define int long long
#define double long double
#define x first
#define y second
#define pii pair<int, int>
const int N = 2e5 + 69;
using namespace std;
int m, k;
struct point
{
    int n, color;
    vector<pii> g;
};
point a[N];
pair<double, int> s[N];
double progress(int k, int c)
{
    int l = 1;
    double sum = 0, res = 0;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        cnt += (s[i].second != c);
        sum += s[i].first;
        while (cnt > k)
        {
            cnt -= (s[l].second != c);
            sum -= s[l].first;
            l++;
        }
        res = max(res, sum);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    cin >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].n >> a[i].color;
        for (int j = 1; j <= a[i].n; j++)
        {
            int x, y;
            cin >> x >> y;
            a[i].g.push_back({x, y});
        }
        a[i].g.push_back(a[i].g[0]);
    }

    for (int i = 1; i <= m; i++)
    {
        int t1 = 0, t2 = 0;
        for (int j = 0; j < a[i].g.size() - 1; j++)
        {
            t1 += (a[i].g[j].x * a[i].g[j + 1].y);
            t2 += (a[i].g[j].y * a[i].g[j + 1].x);
        }
        s[i] = make_pair((double)abs(t1 - t2) / 2 * 1.00, a[i].color);
    }

    sort(s + 1, s + m + 1);
    for (int i = m; i >= 1; i--)
        s[i].first -= s[i - 1].first;
    // for (int i = 1; i <= m; i++)
    //     cout << s[i].first << " " << s[i].second << endl;
    cout << setprecision(1) << fixed;
    double ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans, progress(k, i));
    cout << ans;
    cerr << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}