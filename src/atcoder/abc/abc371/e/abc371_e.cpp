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

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    std::unordered_map<int, int> count_map;

    // 数列の入力を処理
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        count_map[nums[i]]++;
    }

    long long total_sum = 0;
    long long subset_count = (1LL << n) % MOD; // 部分集合の総数 (MODを使ってオーバーフロー防止)

    // 各種類が何回部分集合に登場するかを計算
    for (const auto& entry : count_map) {
        int element = entry.first;
        int count = entry.second;
        
        // この数が登場する部分集合の総数
        long long subset_with_element = (1LL << (count)) - 1;  // この数を含む部分集合の数
        total_sum = (total_sum + subset_with_element) % MOD;
    }

    std::cout << total_sum << std::endl;

    // ----------------------------------------------------------------
    return 0;
}