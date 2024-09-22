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

int countABCSubstrings(const std::string& s) {
    int count = 0;
    // s.size() - 2 を超えない範囲でループする（長さ3の部分文字列を探す）
    for (size_t i = 0; i + 2 < s.size(); ++i) {
        // 部分文字列が "ABC" に一致するかを確認
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            ++count;
        }
    }
    return count;
}

bool charJudge(char c) {
    if (c == 'A' || c == 'B' || c == 'C')return true;
    else false;
}

// 与えられた位置が "ABC" の一部であるかどうかを判定するヘルパー関数
bool isABC(const string& s, int i) {
    if (i < 0 || i + 2 >= s.size()) return false;
    return s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C';
}

int main() {
    int n, q;
    string s;
    
    // 入力
    cin >> n >> q >> s;
    
    // 初期状態の "ABC" のカウント
    int abc_count = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (isABC(s, i)) {
            ++abc_count;
        }
    }
    
    // クエリ処理
    for (int i = 0; i < q; ++i) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;  // 0-indexed に変換
        
        // 変更前の "ABC" 部分をカウントから除去
        for (int j = pos - 2; j <= pos; ++j) {
            if (isABC(s, j)) {
                --abc_count;
            }
        }
        
        // 文字列の更新
        s[pos] = c;
        
        // 変更後の "ABC" 部分をカウントに追加
        for (int j = pos - 2; j <= pos; ++j) {
            if (isABC(s, j)) {
                ++abc_count;
            }
        }
        
        // 現在の "ABC" の数を出力
        cout << abc_count << endl;
    }
    
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // ----------------------------------------------------------------
//     int n, q;
//     cin >> n >> q;
//     string s;
//     cin >> s;
//     vec ans(q);
//     for (int i = 0; i < q; i ++) {
//         int x; char c;
//         cin >> x >> c;
//         if (i == 0) {
//             s[x - 1] = c;
//             ans[i] = countABCSubstrings(s);
//             cout << ans[i] << endl;
//             continue;
//         }
//         if (c == 'A' && !charJudge(s[x - 1]) && x != s.size() && s[x] != 'B') {
//             s[x - 1] = c;
//             ans[i] = ans[i - 1];
//             cout << ans[i] << endl;
//             continue;
//         }
//         if (c == 'B' && !charJudge(s[x - 1]) && x != 1 && x != s.size() && s[x - 2] != 'A' && s[x] != 'C') {
//             s[x - 1] = c;
//             ans[i] = ans[i - 1];
//             cout << ans[i] << endl;
//             continue;
//         }
//         if (c == 'C' && !charJudge(s[x - 1]) && x != 1 && s[x - 2] != 'B') {
//             s[x - 1] = c;
//             ans[i] = ans[i - 1];
//             cout << ans[i] << endl;
//             continue;
//         }
//         s[x - 1] = c;
//         ans[i] = countABCSubstrings(s);
//         cout << ans[i] << endl;
//     }

//     // ----------------------------------------------------------------
//     return 0;
// }