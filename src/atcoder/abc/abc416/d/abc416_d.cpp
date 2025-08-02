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
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        
        // Bをソートして、小さい順に処理
        vector<pair<int, int>> B_indexed(N);
        for (int i = 0; i < N; i++) {
            B_indexed[i] = {B[i], i};
        }
        sort(B_indexed.begin(), B_indexed.end());
        
        // Aを使用可能な状態で管理（multiset使用）
        multiset<int> available_A;
        for (int i = 0; i < N; i++) {
            available_A.insert(A[i]);
        }
        
        long long total_sum = 0;
        
        // 各Bについて最適なAを選択
        for (int i = 0; i < N; i++) {
            int b = B_indexed[i].first;
            
            // b + a >= M となる最小のaを探す
            int target = M - b;
            auto it = available_A.lower_bound(target);
            
            int chosen_a;
            if (it != available_A.end()) {
                // M - b 以上の値が存在する場合
                chosen_a = *it;
            } else {
                // 存在しない場合は最小の値を選ぶ
                chosen_a = *available_A.begin();
            }
            
            total_sum += (long long)(b + chosen_a) % M;
            available_A.erase(available_A.find(chosen_a));
        }
        
        cout << total_sum << "\n";
    }

    // ----------------------------------------------------------------
    return 0;
}