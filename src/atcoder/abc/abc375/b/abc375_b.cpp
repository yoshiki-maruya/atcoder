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

// 2点間のユークリッド距離を計算する関数
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n;
    cin >> n; // 座標の個数nを入力

    vector<pair<double, double>> coordinates(n);
    
    // 各座標を入力
    for (int i = 0; i < n; ++i) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    // 原点(0, 0)から最初の点までの距離
    double totalCost = calculateDistance(0, 0, coordinates[0].first, coordinates[0].second);

    // n個の点を順番に移動するコストを計算
    for (int i = 1; i < n; ++i) {
        totalCost += calculateDistance(coordinates[i - 1].first, coordinates[i - 1].second, coordinates[i].first, coordinates[i].second);
    }

    // 最後の点から原点に戻るコストを加算
    totalCost += calculateDistance(coordinates[n - 1].first, coordinates[n - 1].second, 0, 0);

    // 小数点以下6桁まで表示
    cout << fixed << setprecision(20) << totalCost << endl;

    // ----------------------------------------------------------------
    return 0;
}