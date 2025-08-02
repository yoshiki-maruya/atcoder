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

int n;
int maxP = 0;
vector<int> p, a, b;
vector<ll> cumB;
vector<vector<ll>> results;

bool s_contain(string s, char c) {
    if (s.find(c) != string::npos) {
        return true;
    } else {
        return false;
    }
}

ll max_ll(ll val1, ll val2) {
    return val1 > val2 ? val1 : val2;
}

ll solve_high_tension(int k, ll t) {
    ll target_cumB = t - maxP + cumB[k - 1];
    
    auto it = lower_bound(cumB.begin() + k, cumB.begin() + n + 1, target_cumB);
    int j_idx = distance(cumB.begin(), it);

    if (j_idx > n) {
        ll final_t = t - (cumB[n] - cumB[k - 1]);
        return max_ll(0LL, final_t);
    } else {
        ll tension_at_j = t - (cumB[j_idx] - cumB[k - 1]);
        return results[j_idx + 1][max_ll(0LL, tension_at_j)];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    cin >> n;

    p.resize(n); a.resize(n); b.resize(n);
    cumB.resize(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> a[i] >> b[i];
        if (p[i] > maxP) {
            maxP = p[i];
        }
        cumB[i + 1] = cumB[i] + b[i];
    }

    results.assign(n + 2, vector<ll>(maxP + 1, 0));

    for (int t = 0; t <= maxP; ++t) {
        results[n + 1][t] = t;
    }

    for (int k = n; k >= 1; --k) {
        for (int t = 0; t <= maxP; ++t) {
            ll next_t;
            if (p[k - 1] >= t) {
                next_t = (ll)t + a[k - 1];
            } else {
                next_t = max_ll(0LL, (ll)t - b[k - 1]);
            }

            if (next_t <= maxP) {
                results[k][t] = results[k + 1][(int)next_t];
            } else {
                results[k][t] = solve_high_tension(k + 1, next_t);
            }
        }
    }

    int q;
    cin >> q;

    // 各クエリを処理
    for (int i = 0; i < q; ++i) {
        ll initialX;
        cin >> initialX;

        if (initialX <= maxP) {
            cout << results[1][(int)initialX] << endl;
        } else {
            cout << solve_high_tension(1, initialX) << endl;
        }
    }

    // ----------------------------------------------------------------
    return 0;
}