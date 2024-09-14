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

int dp[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, k;
    cin >> n >> k;
    vec h(n);
    vec cost(n);
    cost.assign(n, INF);
    rep(i, n) cin >> h[i];

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
      if (i == 1) {
        dp[i] = abs(h[i] - h[i-1]);
      }
      else {
        for(int j = 1; j <= k; j++) {
          if (i+j >= n - 1) continue;
          cost[j] = dp[i] + abs(h[i] - h[i + j]);
          cout << cost[j] << endl;
          dp[i] = *min_element(cost.begin(), cost.end());
        }
      }
    }

    cout << dp[n-1] << endl;

    // ----------------------------------------------------------------
    return 0;
}