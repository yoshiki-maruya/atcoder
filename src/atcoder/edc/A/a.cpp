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
    int n;
    cin >> n;
    vec h(n);
    rep(i, n) cin >> h[i];

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
      if (i == 1) {
        dp[i] = abs(h[i] - h[i-1]);
      }
      else {
        dp[i] = min(dp[i-2] + abs(h[i] - h[i-2]), dp[i-1] + abs(h[i] - h[i-1]));
      }
    }

    cout << dp[n-1] << endl;

    // ----------------------------------------------------------------
    return 0;
}