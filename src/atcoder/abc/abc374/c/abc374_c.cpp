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
    vec k(n);
    rep(i, n) cin >> k[i];

    int total_sum = accumulate(k.begin(), k.end(), 0);
    int min_max_sum = total_sum; // 初期化

    // 部署を2つのグループに分ける全ての組み合わせをビットで表現
    for (int mask = 0; mask < (1 << n); ++mask) {
        int group_a_sum = 0;

        // マスクの各ビットが1ならばその部署はグループAに割り当てる
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                group_a_sum += k[i];
            }
        }

        int group_b_sum = total_sum - group_a_sum;
        int max_sum = max(group_a_sum, group_b_sum);
        min_max_sum = min(min_max_sum, max_sum);
    }

    cout << min_max_sum << endl;


    // ----------------------------------------------------------------
    return 0;
}