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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

/* -------------------------------------------------------------------
if (bit & (1 << i)) -> i番目のフラグがたっているか
bit |= (1 << i) -> i番目のフラグをたてる
bit &= ~(1 << i) -> i番目のフラグを消す
__builtin_popcount(bit) -> 何個のフラグが立っているか

bit |= mask -> maskで表された部分のフラグをまとめて立てる
bit &= ~mask -> maskで表された部分のフラグをまとめて消す
bit & mask -> maskで表された部分の情報のみを取り出したもの
------------------------------------------------------------------- */

vec pow_vec{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

vecll pow_vecll{1,        10,        100,        1000,        10000,        100000,       1000000,
                10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};

class UnionFind {
   public:
    int par[100009];
    int siz[100009];

    // N頂点のUnion-Findを作成
    void init(int N) {
        for (int i = 1; i <= N; i++) {
            par[i] = -1;  // 最初は親がない
        }
        for (int i = 1; i <= N; i++) {
            siz[i] = 1;  // 最初はグループの頂点数が1
        }
    }

    // 頂点xの根を返す
    int root(int x) {
        while (true) {
            if (par[x] == -1) {
                // 一個先が無ければここが根
                break;
            }
            x = par[x];
        }
        return x;
    }

    // 要素uとvを結合する
    void unite(int u, int v) {
        int RootU = root(u);
        int RootV = root(v);

        if (RootU == RootV) {
            return;
        }

        if (siz[RootU] < siz[RootV]) {
            par[RootU] = RootV;
            siz[RootU] = siz[RootU] + siz[RootV];
        } else {
            par[RootV] = RootU;
            siz[RootV] = siz[RootV] + siz[RootU];
        }
    }

    // 要素uと要素vが同じグループに属するかどうか
    bool same(int u, int v) {
        if (root(u) == root(v)) {
            return true;
        }

        return false;
    }
};

void print_vec(vec v) {
    rep(i, (int)v.size()) {
        cout << v.at(i);
    }
    cout << endl;
}

void print_vecll(vecll v) {
    rep(i, (int)v.size()) {
        cout << v.at(i);
    }
    cout << endl;
}

vec string_to_vec(string s) {
    vec v(s.size());
    rep(i, (int)s.size()) {
        v.at(i) = s.at(i) - '0';
    }
    return v;
}

char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
}

int alphabet_to_int(char s) {
    return s - 'a';
}

int mmod(int a, int b) {
    a += (abs(a / b) + 1) * b;
    return a % b;
}

ll mmod(ll a, ll b) {
    a += (abs(a / b) + 1) * b;
    return a % b;
}

bool s_contain(string s, char c) {
    if (s.find(c) != string::npos) {
        return true;
    } else {
        return false;
    }
}

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