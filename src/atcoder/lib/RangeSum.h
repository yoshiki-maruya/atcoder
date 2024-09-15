#ifndef RANGE_SUM_H
#define RANGE_SUM_H

#include <vector>;

class RangeSum {
private:
    std::vector<long long> prefixSum;

public:
    // コンストラクタで累積和を計算する
    RangeSum(const std::vector<long long>& nums) {
        long long n = nums.size();
        prefixSum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    // インデックスiからjまでの範囲の和を計算する
    long long rangeSum(int i, int j) {
        return prefixSum[j + 1] - prefixSum[i];
    }
};

#endif