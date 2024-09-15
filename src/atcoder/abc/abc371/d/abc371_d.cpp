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


class RangeSum {
private:
    std::vector<ll> prefixSum;

public:
    // コンストラクタで累積和を計算する
    RangeSum(const std::vector<ll>& nums) {
        ll n = nums.size();
        prefixSum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    // インデックスiからjまでの範囲の和を計算する
    ll rangeSum(ll i, ll j) {
        return prefixSum[j + 1] - prefixSum[i];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, q;
    cin >> n;
    vecll x(n), p(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> p[i];
    cin >> q;
    RangeSum rs(p);

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        auto it1 = lower_bound(x.begin(), x.end(), l);
        auto it2 = upper_bound(x.begin(), x.end(), r);

        // val1の挿入位置
        int index1 = it1 - x.begin();
        // val2の挿入位置
        int index2 = it2 - x.begin() - 1;
        // if (l == r)  {
        //     if(!binary_search(x.begin(), x.end(), l)){
        //         cout << 0 << endl;
        //         continue;
        //     }
        // }
        //cout << index1 << " " << index2 << endl;
        //if (index2 == n) index2--;
        cout << rs.rangeSum(index1, index2) << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}