#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> v1;
int n, m, s, t;
int bfs(int s, const vector<int> &temp, const v1 &ke, vector<bool> &dd)
{
    queue<int> q;
    q.push(s);
    dd[s] = true;
    int r = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : ke[u])
            if (!dd[v] && temp[v] < 0)
            {
                q.push(v);
                dd[v] = true;
            }
            else
                r = max(r, temp[v]);
    }
    return r;
}

vector<int> find_p(int s, int t, const v1 &ke)
{
    int n = ke.size();
    vector<int> trace(n, -1);
    queue<int> q;
    q.push(s);
    trace[s] = s;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : ke[u])
            if (trace[v] < 0)
            {
                q.push(v);
                trace[v] = u;
            }
    }
    vector<int> p;
    int u = t;
    while (u != s)
    {
        p.push_back(u);
        u = trace[u];
    }
    p.push_back(s);
    for (int i = 0, j = p.size() - 1; i < j; i++, j--)
        swap(p[i], p[j]);
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    s--, t--;
    v1 ke(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ke[u - 1].push_back(v - 1);
    }
    vector<int> p = find_p(s, t, ke);
    vector<int> temp(n, -1);
    for (int i = 0; i < (int)p.size(); i++)
    {
        temp[p[i]] = i;
    }

    vector<bool> dd(n, false);
    int r = -1, res = 0;
    for (int u : p)
    {
        if (u != s && u != t && r <= temp[u])
            res++;
        r = max(r, bfs(u, temp, ke, dd));
    }
    cout << res;
    return 0;
}
