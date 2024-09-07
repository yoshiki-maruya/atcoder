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

vecll memo;

ll tribo(int n) {
  if(n == 0) return 0;
  if(n == 1) return 0;
  if(n == 2) return 1;

  if (memo[n] != -1) return memo[n];

  return memo[n] = tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n;
    cin >> n;

    memo.assign(n, -1);
    tribo(n - 1);

    for (auto i : memo) {
      cout << i << endl;
    }
    // ----------------------------------------------------------------
    return 0;
}