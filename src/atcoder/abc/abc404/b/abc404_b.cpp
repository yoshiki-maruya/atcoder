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

#define INF INT_MAX
#define LINF LLONG_MAX

bool s_contain(string s, char c) {
    if (s.find(c) != string::npos) {
        return true;
    } else {
        return false;
    }
}

// 90度右に回転したグリッドを返す
vector<string> rotate(const vector<string>& grid) {
    int n = grid.size();
    vector<string> res(n, string(n, '.'));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res[j][n - 1 - i] = grid[i][j];
    return res;
}

// 2つのグリッドの異なるマスの数を数える
int countDifferences(const vector<string>& a, const vector<string>& b) {
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != b[i][j]) ++cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------

    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> t[i];

    int min_ops = 1e9;
    for (int rot = 0; rot < 4; ++rot) {
        int diff = countDifferences(s, t);
        int ops = diff + rot;  // 色変更 + 回転回数
        min_ops = min(min_ops, ops);
        s = rotate(s);
    }

    cout << min_ops << endl;

    // ----------------------------------------------------------------
    return 0;
}