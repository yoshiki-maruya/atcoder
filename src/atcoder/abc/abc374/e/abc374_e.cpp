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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto canAchieve = [&](int target) -> bool {
        vector<int> dp(x + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> new_dp = dp;
            for (int budget = 0; budget <= x; ++budget) {
                if (dp[budget] == -1) continue;

                // s_iの機械でtargetを達成するために必要な台数
                int needed_s = (target + a[i] - 1) / a[i]; // target / a[i] の切り上げ
                int cost_s = needed_s * p[i];
                if (budget + cost_s <= x) {
                    new_dp[budget + cost_s] = max(new_dp[budget + cost_s], target);
                }

                // t_iの機械でtargetを達成するために必要な台数
                int needed_t = (target + b[i] - 1) / b[i]; // target / b[i] の切り上げ
                int cost_t = needed_t * q[i];
                if (budget + cost_t <= x) {
                    new_dp[budget + cost_t] = max(new_dp[budget + cost_t], target);
                }
            }
            dp = move(new_dp);
        }

        // すべての工程でtargetを達成できるかチェック
        for (int budget = 0; budget <= x; ++budget) {
            if (dp[budget] >= target) {
                return true;
            }
        }
        return false;
    };

    // 二分探索で最小の製造量の最大値を求める
    int left = 0, right = 1e6;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canAchieve(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    // ----------------------------------------------------------------
    return 0;
}