#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string a;
int main()
{
    int res = 1e5;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    cin >> a;
    while (k--)
    {
        string b;
        cin >> b;
        for (auto i = a.begin(); i != a.end(); i++)
        {
            auto j = i;
            int dis = 0;
            for (auto b : b)
            {
                if (j == a.end())
                    j = a.begin();
                if (*j != b)
                    dis++;
                j++;
            }
            if (res > dis)
                res = dis;
        }
    }
    cout << res;
    return 0;
}
