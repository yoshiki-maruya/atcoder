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

#define INF 4e18
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

    int N, M;
    cin >> N >> M;

    vector<vector<long long>> dist(N, vector<long long>(N, INF));
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        --u; --v;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }

    int K;
    long long T;
    cin >> K >> T;

    vector<int> airport_nodes;
    vector<bool> has_airport(N, false);
    for (int i = 0; i < K; ++i) {
        int d;
        cin >> d;
        --d;
        if (!has_airport[d]) {
            has_airport[d] = true;
            airport_nodes.push_back(d);
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    vector<long long> min_dist_to_airport(N, INF);
    auto update_min_dist_from_all = [&]() {
        min_dist_to_airport.assign(N, INF);
        if (airport_nodes.empty()) return;
        for (int i = 0; i < N; ++i) {
            for (int ap_node : airport_nodes) {
                min_dist_to_airport[i] = min(min_dist_to_airport[i], dist[i][ap_node]);
            }
        }
    };
    
    update_min_dist_from_all();
    
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            long long t;
            cin >> u >> v >> t;
            --u; --v;
        
            if (t < dist[u][v]) {
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        // i -> u -> v -> j という経路
                        long long path1 = (dist[i][u] == INF || dist[v][j] == INF) ? INF : dist[i][u] + t + dist[v][j];
                        // i -> v -> u -> j という経路
                        long long path2 = (dist[i][v] == INF || dist[u][j] == INF) ? INF : dist[i][v] + t + dist[u][j];
                        
                        dist[i][j] = min({dist[i][j], path1, path2});
                    }
                }

                update_min_dist_from_all();
            }
        } else if (type == 2) { // 空港追加
            int x;
            cin >> x;
            --x;
            if (!has_airport[x]) {
                has_airport[x] = true;
                airport_nodes.push_back(x);
                for (int i = 0; i < N; ++i) {
                    min_dist_to_airport[i] = min(min_dist_to_airport[i], dist[i][x]);
                }
            }
        } else {
            long long total_dist = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    long long current_shortest = dist[i][j];
                    
                    if (!airport_nodes.empty() && min_dist_to_airport[i] != INF && min_dist_to_airport[j] != INF) {
                        long long air_path = min_dist_to_airport[i] + T + min_dist_to_airport[j];
                        current_shortest = min(current_shortest, air_path);
                    }
                    
                    if (current_shortest != INF) {
                        total_dist += current_shortest;
                    }
                }
            }
            cout << total_dist << "\n";
        }
    }

    return 0;
}