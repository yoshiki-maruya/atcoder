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
    int n, m;
    cin >> n >> m;
    vec a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int i = 0, j = 0;
    long long min_diff = LLONG_MAX;

    while (i < n && j < m) {
        long long diff = abs(a[i] - b[j]);
        min_diff = min(min_diff, diff);

        // より小さな差を目指してポインタを移動
        if (a[i] < b[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    cout << min_diff << endl;

    // ----------------------------------------------------------------
    return 0;
}