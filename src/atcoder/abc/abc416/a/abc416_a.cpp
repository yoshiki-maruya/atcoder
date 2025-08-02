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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, l, r;
    string s;
    cin >> n >> l >> r;
    cin >> s;

    // 入力チェック（念のため）
    if (s.length() != n) {
        cerr << "文字列の長さが n と一致しません。" << endl;
        return 1;
    }

    // l〜rの範囲（1-indexed）を 0-indexed に変換してループ
    for (int i = l - 1; i <= r - 1; ++i) {
        if (s[i] != 'o') {
            cout << "No" << endl;
            return 0;
        }
    }

    // すべて 'o' だった
    cout << "Yes" << endl;

    // ----------------------------------------------------------------
    return 0;
}