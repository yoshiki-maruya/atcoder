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
    string s;
    cin >> s;
    string t = "";
    vector<string> list = {"maerd", "remaerd", "esare", "resare"};

    irep(i, s.length()) {
      t += s[i];
      if (t.length() == 5 || t.length() == 6 || t.length() == 7) {
        for (auto l : list) {
          if (t == l) {
            s.erase(s.size() - t.size());
            t = "";
          }
        }
      }
    }
    if (s.length() == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    // ----------------------------------------------------------------
    return 0;
}