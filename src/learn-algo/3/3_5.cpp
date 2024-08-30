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

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n; cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];
    bool flag = false;
    int ans = 0;

    while(!flag) {
        rep(i, n) {
            if(a[i] % 2 == 0) {
                a[i] = a[i] / 2;
            }
            else {
                flag = true;
            }
        }
        if (flag) break;
        ans++;
    }
    cout << ans << endl;
    // ----------------------------------------------------------------
    return 0;
}