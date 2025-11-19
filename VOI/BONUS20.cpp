#include <bits/stdc++.h>
using namespace std;
#define name "TASK"
#define endl '\n'
#define Alisa signed main(void)
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()

bool minimize(int &x, const int &y) {if (x > y) {x = y;  return true;} else return false;}
bool maximize(int &x, const int &y) {if (x < y) {x = y;  return true;} else return false;}

const int N = 2e3 + 69;
int n, x, y, s;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char a[N][N];
void solve()
{
    cin >> n >> x >> y >> s;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    int id = 1; // uu tien di len
    int u, v;
    for(int i = 1; i <= s; i++) {
        u = x + dx[id];
        v = y + dy[id];
        if (u < 1 || u > n || v < 1 || v > n) { // ngoai me cung
            x = u;
            y = v;
        }
        else { // trong me cung
            while(a[v][u] == '#') {
                id = (id - 1 < 0) ? 3 : id - 1; // di chuyen
                u = x + dx[id];
                v = y + dy[id];
            }
            x = u, y = v;
        }
    }
    cout << x << " " << y << endl;
}

Alisa {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    // cerr << "Time : " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
