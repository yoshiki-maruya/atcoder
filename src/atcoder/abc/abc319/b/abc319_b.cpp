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

// N の約数をすべて求める関数
vector<long long> calc_divisors(long long N) {
    // 答えを表す集合
    vector<long long> res;

    // 各整数 i が N の約数かどうかを調べる
    for (long long i = 1; i * i <= N; ++i) {
        // i が N の約数でない場合はスキップ
        if (N % i != 0) continue;

        // i は約数である
        res.push_back(i);

        // N ÷ i も約数である (重複に注意)
        if (N / i != i) res.push_back(N / i);
    }

    // 約数を小さい順に並び替えて出力
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------

    int n;
    bool flag = true;
    cin >> n;
    string ans;
    vecll divisors = calc_divisors(n);

    rep(i, n + 1) {
        flag = true;
        for(int j = 1; j <= 9; j++) {
            if (n % j == 0 && i % (n / j) == 0) {
                ans += j + '0';
                flag = false;
                break;
            }
        }
        if (flag) {
            ans += "-";
        }
    }

    cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}