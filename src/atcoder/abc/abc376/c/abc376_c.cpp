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
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);

    // おもちゃと箱の大きさを入力
    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> boxes[i];
    }

    // おもちゃと箱をソート
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // 新しい箱が必要な最小の大きさを求める
    int min_new_box_size = -1;
    for (int i = 0; i < n - 1; i++) {
        if (toys[i] > boxes[i]) {
            // 既存の箱に収まらないおもちゃがあった場合、新しい箱が必要
            min_new_box_size = toys[i];
            break;
        }
    }

    // 最後の残ったおもちゃ用に追加する必要があるか確認
    if (min_new_box_size == -1) {
        // 既存の箱に全て収まる場合、最後の箱を追加するための判定
        if (toys[n - 1] > boxes[n - 2]) {
            // 既存の最大の箱より大きいおもちゃがある場合
            min_new_box_size = toys[n - 1];
        }
    }

    // 結果を出力
    if (min_new_box_size == -1) {
        cout << -1 << endl;  // 追加の箱が不要な場合
    } else {
        cout << min_new_box_size << endl;  // 新しい箱の最小の大きさ
    }

    // ----------------------------------------------------------------
    return 0;
}