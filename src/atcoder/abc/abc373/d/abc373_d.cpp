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

#define LINF LLONG_MAX

bool s_contain(string s, char c) {
    if (s.find(c) != string::npos) {
        return true;
    } else {
        return false;
    }
}

struct Edge {
    int u, v, w;
};

// 幅優先探索による連結成分内の頂点の値を決定
void bfs(int start, const vector<vector<Edge>>& adj, vector<long long>& x, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    x[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (const auto& edge : adj[node]) {
            int next = edge.v;
            if (!visited[next]) {
                visited[next] = true;
                x[next] = x[node] + edge.w;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, -w}); // 逆向きの辺も追加しておく
    }

    const long long INF = numeric_limits<long long>::max();
    vector<long long> x(n + 1, INF);
    vector<bool> visited(n + 1, false);

    // 各連結成分をBFSで探索して値を求める
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bfs(i, adj, x, visited);
        }
        cout << x[i] << (i == n ? "\n" : " ");
    }

    // ----------------------------------------------------------------
    return 0;
}