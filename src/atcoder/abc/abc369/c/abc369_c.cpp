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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    ll n;
    ll ans = 0;
    ll index = 0;
    cin >> n;
    vecll a(n);
    rep(i, n) cin >> a[i];

    ll prev = 0;
    ll carr = 0;

    rep(i, n) {
        ans++;
        prev = 1000000007;
        if (i == n - 1) break;
        krep(j, i + 1, n) {
            if (prev == 1000000007) {
                ans++;
                prev = a[j] - a[i];
                continue;
            }
            carr = a[j] - a[j - 1];
            if (carr == prev) {
                ans++;
            }
            else break;
        }
    }

    cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}