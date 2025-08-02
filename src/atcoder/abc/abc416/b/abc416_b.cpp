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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    string s;
    cin >> s;
    int n = s.size();
    string t = s;

    // 前回のoの位置（初期値は-1で無効）
    for (int i = 0; i < n;) {
        if (s[i] == '#') {
            t[i] = '#';
            ++i;
        } else {
            // '.' の区間を探す
            int j = i;
            while (j < n && s[j] == '.') ++j;

            // i から j-1 までが '.' 区間
            // その中の最初の位置に 'o' を1個置く（任意で最大化）
            t[i] = 'o';
            for (int k = i + 1; k < j; ++k) {
                t[k] = '.';
            }
            i = j;
        }
    }

    cout << t << endl;

    // ----------------------------------------------------------------
    return 0;
}