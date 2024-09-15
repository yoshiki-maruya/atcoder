#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>
#define Graph vector<vector<int>>
#define wGraph vector<vector<Edge>>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
        cout << i;
  }
*/
/* for (auto& x: X) {
        cin >> x;
    }
*/

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define zrep(i, n) for (int i = 0; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/


bool s_contain(string s, char c) {
    if (s.find(c) != string::npos) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, m;
    cin >> n >> m;
    int idx;
    char g;
    bool flag = false;
    vector<string> ans(m);
    vector<bool> f(n);
    f.assign(n, false);
    int tmp = 1;
    string gen = "";
    for (int i = 0; i < m; i++) {
        cin >> idx >> g;
        flag = false;
        if (tmp != idx) {
            gen = "";
        }
        else {
            if (s_contain(gen, 'M')) flag = true;
        }
        tmp = idx;
        if (!flag && !f[idx - 1] && g == 'M') {
            ans.push_back("Yes");
            f[idx - 1] = true;
        }
        else {
            ans.push_back("No");
        }
        gen += g;
    }

    for (auto x : ans) {
        cout << x << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}