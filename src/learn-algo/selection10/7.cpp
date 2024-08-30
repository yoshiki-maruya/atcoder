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
    vec d(n);
    rep(i, n) cin >> d[i];

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    cout << d.size() << endl;
    
    // ----------------------------------------------------------------
    // より綺麗な解法　set型を使用すると重複を取り除ける
    /*
      int N;
      int d[110];
      cin >> N;
      for (int i = 0; i < N; ++i) cin >> d[i];

      set<int> values; // insert するときに重複を取り除いてくれます
      for (int i = 0; i < N; ++i) {
          values.insert(d[i]); // 挿入します
      }

      // set のサイズを出力します
      cout << values.size() << endl;
    */
    return 0;
}