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
    int n;
    vec l;
    vec r;
    int ans = 0;
    cin >> n;
    vec a(n);
    vector<char> s(n);

    rep(i, n) {
        cin >> a[i] >> s[i];
    }

    rep(i, n) {
        if (s[i] == 'L') l.push_back(a[i]);
        else r.push_back(a[i]);
    }
    int lsize = l.size();
    int rsize = r.size();

    if (lsize > 0) {
        rep(i, lsize) {
            if(i == lsize - 1) break;
            //cout << l[i] << " " << l[i + 1] << endl;
            ans += abs(l[i] - l[i + 1]);
        }
    }

    if (rsize > 0) {
        rep(i, rsize - 1) {
            if(i == rsize) break;
            ans += abs(r[i] - r[i + 1]);
        }
    }

    cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}