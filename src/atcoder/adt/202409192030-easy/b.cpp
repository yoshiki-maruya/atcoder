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

int alphabet_to_int(char s) {
    return s - 'a';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    string s;
    cin >> s;

    // 文字の出現回数をカウントするためのハッシュマップ
    unordered_map<char, int> freq;

    // 文字の出現回数をカウント
    for (char c : s) {
        freq[c]++;
    }

    // 一回しか出現しない文字を探して、その位置を出力
    for (int i = 0; i < s.size(); ++i) {
        if (freq[s[i]] == 1) {
            cout << i + 1 << endl; // 位置は1から始まるため+1
            break;
        }
    }

    // ----------------------------------------------------------------
    return 0;
}