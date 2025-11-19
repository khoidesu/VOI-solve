#include <bits/stdc++.h>
using namespace std;
const int MASK189 = (1 << 1) + (1 << 8) + (1 << 9);
int n;
int res = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> f(1024), f1(1024);
    cin >> n;
    vector<int> a(n);
    for (auto &a : a)
        cin >> a;
    sort(a.begin(), a.end());
    f.assign(1024, -1);
    f[0] = 0;
    f[1] = 1;
    for (int i = 1; i < n; i++)
    {
        int d = a[i] - a[i - 1];
        f1.assign(1024, -1);
        for (int k = 0; k < 1024; k++)
        {
            if (f[k] >= 0)
            {
                int k1 = d >= 10 ? 0 : (k << d) & 1023;
                f1[k1] = max(f1[k1], f[k]);
                if ((k1 & MASK189) == 0)
                {
                    f1[k1 | 1] = max(f1[k1 | 1], f[k] + 1);
                }
            }
        }
        f.swap(f1);
    }
    for (int k = 0; k < 1024; k++)
    {
        res = max(res, f[k]);
    }
    cout << n - res;
    return 0;
}
