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
    string s;
    string formula;
    ll currentNumber;
    vecll nums;
    ll ans = 0;
    cin >> s;
    if (s.length() == 1) {
      cout << s << endl;
      return 0;
    }
    for (int bit = 0; bit < (1 << (s.length() - 1)); bit++) {
      formula = "";
      rep(i, s.length()) {
        if (bit & (1 << i)) {
          formula += s[i];
          formula += '+';
        }
        else {
          formula += s[i];
        }
      }
      currentNumber = 0;

      // 文字列を1文字ずつ走査
      for (char c : formula) {
          if (c == '+') {
              // '+' が見つかったら、現在の数字をベクターに追加
              nums.push_back(currentNumber);
              currentNumber = 0; // 数字の初期化
          } else if (isdigit(c)) {
              // 数字の場合、桁を進める
              currentNumber = currentNumber * 10 + (c - '0');
          }
      }
      // 最後の数字をベクターに追加
      nums.push_back(currentNumber);
    }

    for (auto num : nums) {
        ans += num;
    }

    cout << ans << endl;

    
    // ----------------------------------------------------------------
    return 0;
}