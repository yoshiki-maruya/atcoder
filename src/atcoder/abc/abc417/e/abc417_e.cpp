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
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            sort(adj[i].begin(), adj[i].end());
        }

        vector<int> path;
        vector<bool> visited(n + 1, false);

        function<bool(int)> dfs = 
            [&](int currentNode) -> bool {
            
            visited[currentNode] = true;
            path.push_back(currentNode);

            if (currentNode == y) {
                return true;
            }

            for (int nextNode : adj[currentNode]) {
                if (!visited[nextNode]) {
                    if (dfs(nextNode)) {
                        return true;
                    }
                }
            }

            path.pop_back();
            return false;
        };

        dfs(x);

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    // ----------------------------------------------------------------
    return 0;
}


// 以下も正解
// バックトラック処理のvisited[next] = false;が余計で不正解になっていた。（現在削除してAC）
// #pragma GCC optimize("Ofast")

// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define vec vector<int>
// #define vecd vector<double>
// #define vecll vector<ll>
// #define Graph vector<vector<int>>
// #define wGraph vector<vector<Edge>>

// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// /* rep(i, n) {
//         cout << i;
//   }
// */
// /* for (auto& x: X) {
//         cin >> x;
//     }
// */

// #define krep(i, k, n) for (int i = k; i < (int)(n); i++)

// #define prep(i, n) for (int i = 1; i <= (int)(n); i++)

// #define zrep(i, n) for (int i = 0; i <= (int)(n); i++)

// #define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

// #define all(v) v.begin(), v.end()
// /*
//   vector<int> v = {2, 3, 1}
//   sort(all(v))
// */

// #define INF INT_MAX
// #define LINF LLONG_MAX

// bool s_contain(string s, char c) {
//     if (s.find(c) != string::npos) {
//         return true;
//     } else {
//         return false;
//     }
// }

// vector<int> bestPath;
// bool found;

// void dfs(int current, int target, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& currentPath) {
//     if (found) return;
    
//     if (current == target) {
//         bestPath = currentPath;
//         found = true;
//         return;
//     }
    
//     for (int next : adj[current]) {
//         if (!visited[next]) {
//             visited[next] = true;
//             currentPath.push_back(next);
//             dfs(next, target, adj, visited, currentPath);
//             currentPath.pop_back();
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // ----------------------------------------------------------------
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n, m, x, y;
//         cin >> n >> m >> x >> y;
        
//         vector<vector<int>> adj(n + 1);
        
//         for (int i = 0; i < m; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         for (int i = 1; i <= n; i++) {
//             sort(adj[i].begin(), adj[i].end());
//         }
        
//         bestPath.clear();
//         found = false;
//         vector<bool> visited(n + 1, false);
//         vector<int> currentPath;
        
//         visited[x] = true;
//         currentPath.push_back(x);
        
//         dfs(x, y, adj, visited, currentPath);

//         for (int i = 0; i < bestPath.size(); i++) {
//             cout << bestPath[i] << " ";
//         }
//         cout << endl;
//     }
//     // ----------------------------------------------------------------
//     return 0;
// }