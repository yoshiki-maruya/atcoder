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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    ll total = 0;
    ll maxA = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
        maxA = max(maxA, a[i]);
    }

    sort(a.begin(), a.end());
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + a[i];

    while (q--) {
        ll b;
        cin >> b;
        if (b > maxA) {
            cout << -1 << endl;
            continue;
        }
        ll t = b - 1;
        int k = upper_bound(a.begin(), a.end(), t) - a.begin();
        ll sumMin = pref[k] + (ll)(n - k) * t;
        ll ans = max(b, sumMin + 1);
        cout << ans << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}