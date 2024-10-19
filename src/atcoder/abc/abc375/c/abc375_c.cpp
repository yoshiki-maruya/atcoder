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

// グリッドの色変換を行う関数
void transformGrid(int n, vector<vector<char>>& a) {
    // i行目の処理（上から順にn/2まで処理）
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i; ++j) {
            // 上側の領域をそのまま下側にコピー
            a[n - 1 - j][n - 1 - i] = a[i][j];
            a[n - 1 - i][j] = a[i][j]; // 左下領域も置き換え
            a[j][i] = a[i][j]; // 右上領域も置き換え
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------

    int n;
    cin >> n;
    
    vector<vector<char>> a(n, vector<char>(n));
    
    // グリッドの入力を受け取る
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    // 色変え操作を実行
    transformGrid(n, a);

    // 結果を出力
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}