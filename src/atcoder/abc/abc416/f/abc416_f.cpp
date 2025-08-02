#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 十分に小さい負の数を定義（オーバーフローを避けるためlong longの最大値の半分程度）
const long long INF = -1e18; 

int N, K;
vector<long long> A;
vector<vector<int>> adj;
vector<vector<vector<long long>>> dp;

/*
dp[u][k][state]: 頂点uを根とする部分木で、k本のパスを選んだ時の重みの最大値
state 0: uが白色
state 1: uが黒色で、uを含むパスが部分木内で完結
state 2: uが黒色で、uを端点として親方向にパスが伸びる
*/

void dfs(int u, int p) {
    // DPテーブルを初期化
    // uが葉であるかのように振る舞う初期状態
    dp[u][0][0] = 0;
    if (K >= 1) {
        // u自身のみからなるパスを1本選ぶ場合
        dp[u][1][1] = A[u - 1]; // uで完結するパス
        dp[u][1][2] = A[u - 1]; // uから親へ伸びるパス
    }

    // 子ノードの結果をマージしていく
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        // マージ用の一時DPテーブル
        vector<vector<long long>> tmp_dp(K + 1, vector<long long>(3, INF));

        // uの現在までの状態(ku本)と、子vの状態(kv本)を組み合わせる
        for (int ku = 0; ku <= K; ++ku) {
            for (int kv = 0; kv <= K; ++kv) {
                int k_total = ku + kv;
                if (k_total > K) continue;

                // --- Case 1: u-v 間の辺を使わない ---
                // v側のパスはvの部分木内で完結している必要がある
                long long v_comp_val = max(dp[v][kv][0], dp[v][kv][1]);
                if (v_comp_val <= INF / 2) continue;
                
                // uが白色の場合
                if (dp[u][ku][0] > INF / 2) {
                    tmp_dp[k_total][0] = max(tmp_dp[k_total][0], dp[u][ku][0] + v_comp_val);
                }
                // uが黒色(完結)の場合
                if (dp[u][ku][1] > INF / 2) {
                    tmp_dp[k_total][1] = max(tmp_dp[k_total][1], dp[u][ku][1] + v_comp_val);
                }
                // uが黒色(親へ)の場合
                if (dp[u][ku][2] > INF / 2) {
                    tmp_dp[k_total][2] = max(tmp_dp[k_total][2], dp[u][ku][2] + v_comp_val);
                }

                // --- Case 2: u-v 間の辺を使う ---
                // v側から親(u)へパスが伸びている必要がある
                long long v_up_val = dp[v][kv][2];
                if (v_up_val <= INF / 2) continue;

                // (u:白 0) + (v->u 2) => (u:黒,完結 1)
                // vからのパスがuで終点となる。uが新たに塗られるのでA[u-1]を加算。
                // パス本数は ku + kv
                if (dp[u][ku][0] > INF / 2) {
                     tmp_dp[k_total][1] = max(tmp_dp[k_total][1], dp[u][ku][0] + v_up_val + A[u - 1]);
                }
                
                // (u:黒,完結 1) + (v->u 2) => (u:黒,完結 1)
                // vからのパスとuで別のパスが連結し、uで完結する大きなパスになる。
                // パス本数は1つ減る (ku + kv - 1)
                int k_merged = ku + kv - 1;
                if (k_merged >= 0 && k_merged <= K && dp[u][ku][1] > INF / 2) {
                    tmp_dp[k_merged][1] = max(tmp_dp[k_merged][1], dp[u][ku][1] + v_up_val);
                }

                // (u:黒,親へ 2) + (v->u 2) => (u:黒,親へ 2)
                // vからのパスがuを経由して親へ抜けていく。
                // パス本数は1つ減る (ku + kv - 1)
                if (k_merged >= 0 && k_merged <= K && dp[u][ku][2] > INF / 2) {
                    tmp_dp[k_merged][2] = max(tmp_dp[k_merged][2], dp[u][ku][2] + v_up_val);
                }
            }
        }
        // マージ結果をuのDPテーブルに反映
        dp[u] = tmp_dp;
    }
}

int main() {
    // 高速化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    adj.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // DPテーブルを確保し、-INFで初期化
    dp.resize(N + 1, vector<vector<long long>>(K + 1, vector<long long>(3, INF)));

    // 根を1としてDFSを開始
    dfs(1, 0);

    long long max_val = 0;
    // 根(頂点1)での最終結果を集計
    // 0回からK回までの全てのパス本数の可能性を考慮
    for (int k = 0; k <= K; ++k) {
        // 根が白、または根を含むパスが完結する場合
        max_val = max(max_val, dp[1][k][0]);
        max_val = max(max_val, dp[1][k][1]);
    }

    cout << max_val << endl;

    return 0;
}
