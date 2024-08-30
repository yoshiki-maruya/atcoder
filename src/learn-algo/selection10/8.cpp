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
    cin >> n;
    ll yen;
    cin >> yen;
    int a = -1, b = -1, c = -1;
    bool flag = false;

    zrep(i, n) {
      zrep(j, n) {
        int k = n - i - j;
        if(k >= 0 && 10000*i + 5000*j + 1000*k == yen) {
          a = i;
          b = j;
          c = k;
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    cout << a << " " << b << " " << c << endl;
    // ----------------------------------------------------------------
    return 0;
}