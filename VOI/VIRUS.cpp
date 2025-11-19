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

const int N = 2e5 + 69;
int q, n;
string s;

bool cmp(string a, string b, int k){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt <= k;
}

namespace one {
    bool subtask() {
        return n <= 300;
    }
    void Solve() {
        for(int i = 1; i <= q; i++) {
        int k; cin >> k;
        int res = 0;
        for(int i = 1; i <= n / 2; i++) {
            for(int j = i; j <= n - (i * 2) + 1; j++) {
                if (j + (j - i + 1) > n) continue;
                string tmp1 = "", tmp2 = "";
                for(int c = i; c <= j; c++) tmp1 += s[c];
                for(int c = j+1; c <= j+(j-i+1); c++) tmp2 += s[c];
                if (cmp(tmp1, tmp2, k)) maximize(res, (int)tmp1.size());
            }
        }
        cout << res << endl;
    }
    }
}

namespace two {
    void Solve() {
        int res = 1, cnt = 1;
        s[n + 1] = '@';
        for(int i = 2; i <= n + 1; i++) {
            if (s[i] == s[i-1])
                cnt++;
            else if (s[i] != s[i-1]) {
                maximize(res, cnt);
                cnt = 1;
            }
        }
        res /= 2;
        for(int i = 1; i <= q; i++) {
            int k; cin >> k;
            cout << res << endl;
        }
    }
}
namespace three {
    int f[3005];

    void Solve() {
        for(int i = n / 2; i >= 1; i--) {
            int cnt = 0;
            for(int j = 1; j <= i; j++) {
                if (s[j] != s[i + j]) cnt++;
            }
            f[i] = cnt;
            for(int j = i + 1; j <= n - i; j++) {
                cnt += (s[j] != s[i + j]) - (s[j - i] != s[j]);
                minimize(f[i], cnt);
            }
        }
        for(int j = 1; j <= q; j++) {
            int k; cin >> k;
            for(int i = n / 2; i >= 0; i--) {
                if (f[i] <= k) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}
void solve()
{
    cin >> q >> s;
    n = s.size();
    s = ' ' + s;
    return three::Solve();

}

Alisa {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(name ".inp", "r", stdin);
    freopen(name ".out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    // cerr << "Time : " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
    return 0;
}
