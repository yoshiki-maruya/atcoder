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

bool isPartialSum(vec &v, int i, int sum, vector<vector<bool>> &memo) {
  if(i == 0) {
    if(sum == 0) return true;
    else return false;
  }

  if(memo[i - 1][sum] || memo[i - 1][sum - v[i - 1]]) return true;

  memo[i - 1][sum] = isPartialSum(v, i - 1, sum, memo);
  memo[i - 1][sum - v[i - 1]] = isPartialSum(v, i - 1, sum - v[i - 1], memo);

  if(memo[i - 1][sum]) return true;

  if(memo[i - 1][sum - v[i - 1]]) return true;

  return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, w;
    cin >> n >> w;
    vec a(n);
    vector<vector<bool>> memo;
    rep(i, n) cin >> a[i];
    memo.assign(n, vector<bool>(w, false));

    if(isPartialSum(a, n, w, memo)) cout << "Yes" << endl;
    else cout << "No" << endl;
    // ----------------------------------------------------------------
    return 0;
}