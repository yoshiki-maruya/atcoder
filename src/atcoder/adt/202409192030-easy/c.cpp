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
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    string mix = s[0];
    int ans = 0;
    int tmp = 0;

    rep(i, n) {
        int idx = 0;
        for (auto x : s[i]) {
            if (x == 'x') {
                mix[idx] = 'x';
            }
            idx++;
        }
    }
    
    for (auto x : mix) {
        if (x == 'o') tmp++;
        else {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }

    ans = max(ans, tmp);

    cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}