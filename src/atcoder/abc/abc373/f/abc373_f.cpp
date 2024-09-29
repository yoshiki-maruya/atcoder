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
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> w(N), v(N);

    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    // DP配列を初期化
    vector<long long> dp(W + 1, -1e18);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        // 現在の品物に対するDPの更新
        for (long long current_weight = 0; current_weight <= W; ++current_weight) {
            if (dp[current_weight] < 0) continue;

            long long remaining_weight = W - current_weight;
            long long max_k = remaining_weight / w[i];

            // 二次関数 k*v[i] - k^2 の最大化を考える
            long long optimal_k = min(max_k, v[i] / 2);  // 最適なkは二次関数の頂点付近

            for (long long k = max(1LL, optimal_k - 5); k <= min(max_k, optimal_k + 5); ++k) {
                long long weight = k * w[i];
                if (current_weight + weight > W) break;

                long long happiness = k * v[i] - k * k;
                dp[current_weight + weight] = max(dp[current_weight + weight], dp[current_weight] + happiness);
            }
        }
    }

    // 最大のうれしさを探す
    long long max_happiness = *max_element(dp.begin(), dp.end());
    cout << max_happiness << endl;

    // ----------------------------------------------------------------
    return 0;
}