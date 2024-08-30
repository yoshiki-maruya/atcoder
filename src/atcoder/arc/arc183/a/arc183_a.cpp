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


// 階乗を計算する関数
ll factorial(int n) {
    ll result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// 重複を考慮して並び順の数を求める関数
ll countPermutations(vecll& nums) {
    map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    ll totalPermutations = factorial(nums.size());

    for (auto& [num, count] : freq) {
        totalPermutations /= factorial(count);
    }

    return totalPermutations;
}

vecll getKthPermutation(vecll& nums, int k) {
    sort(nums.begin(), nums.end());
    
    // next_permutation を k-1 回実行して k 番目の順列を得る
    for (int i = 1; i < k; ++i) {
        next_permutation(nums.begin(), nums.end());
    }
    
    return nums;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------

    int n, k;
    cin >> n;
    cin >> k;

    vecll sequence;
    
    // 数列を生成
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            sequence.push_back(i);
        }
    }

    for (int num : sequence) {
        cout << num << " ";
    }

    sort(sequence.begin(), sequence.end());
    int target = (countPermutations(sequence) + 1) / 2;
    vecll result = getKthPermutation(sequence, target);

    // 結果を出力
    for (int num : result) {
        cout << num << " ";
    }
    // ----------------------------------------------------------------
    return 0;
}