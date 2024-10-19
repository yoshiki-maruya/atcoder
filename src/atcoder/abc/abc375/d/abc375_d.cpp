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

ll countPalindromicTriplets(const string& s) {
    int n = s.size();
    vector<ll> left(26, 0);  // 各文字の左側の出現回数を記録 (A-Z)
    vector<ll> right(26, 0); // 各文字の右側の出現回数を記録 (A-Z)
    
    // 最初に全ての文字の出現回数をrightに記録
    for (char c : s) {
        right[c - 'A']++;
    }

    ll count = 0;

    // 中央の位置jを1つずつ考え、左側と右側の出現回数を使って数える
    for (int j = 0; j < n; ++j) {
        right[s[j] - 'A']--;  // 現在位置の文字s[j]を右側から減らす

        // s[i] == s[k]を満たす文字を左側と右側の出現回数でカウント
        for (int i = 0; i < 26; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                count += left[i] * right[i];
            }
        }

        // 現在位置s[j]を左側の出現回数に追加
        left[s[j] - 'A']++;
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    string s;
    cin >> s;

    ll result = countPalindromicTriplets(s);
    cout << result << endl;

    // ----------------------------------------------------------------
    return 0;
}