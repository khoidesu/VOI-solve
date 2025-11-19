#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
class FenwickTree
{
private:
    int mi[N], ma[N];

public:
    void init()
    {
        for (int i = 0; i < N; ++i)
        {
            mi[i] = 1e9;
            ma[i] = -1e9;
        }
    }
    void update(bool t, int x, int value)
    {
        for (; x > 0; x -= x & -x)
            if (t)
                ma[x] = max(ma[x], value);
            else
                mi[x] = min(mi[x], value);
    }
    int get(bool t, int x)
    {
        int res = t ? -1e9 : 1e9;
        for (; x < N; x += x & -x)
            if (t)
                res = max(res, ma[x]);
            else
                res = min(res, mi[x]);
        return res;
    }
} bit;

int n, k, m;
int a[N], val[N];
pair<int, int> b[N];
void init()
{
    sort(b, b + n + 1);
    for (int i = 0; i <= n; ++i)
    {
        if (!i || b[i].first != b[i - 1].first)
            m++;
        val[m] = b[i].first;
        a[b[i].second] = m;
    }
}

bool ok(int lim)
{
    bit.init();
    int mi, ma;
    bit.update(0, a[0], 0);
    bit.update(1, a[0], 0);
    for (int i = 1; i <= n; ++i)
    {
        int tmp = lower_bound(val + 1, val + m + 1, val[a[i]] - lim) - val;
        mi = bit.get(0, tmp) + 1;
        ma = bit.get(1, tmp) + 1;
        bit.update(0, a[i], mi);
        bit.update(1, a[i], ma);
    }
    return mi <= k && k <= ma;
}

void bin_ans()
{
    int l = -1e9, r = 1e9, ans;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        b[i] = make_pair(a[i], i);
    }
    init();
    bin_ans();
    return 0;
}
