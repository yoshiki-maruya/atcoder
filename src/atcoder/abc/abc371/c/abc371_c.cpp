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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, mg, mh;
    cin >> n;
    bool g[n][n]={}, h[n][n]={};
    int a[n][n]={};
    int ans = 2e9;

    cin >> mg;
    rep(i, mg) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        // g[u].push_back(v);
        // g[v].push_back(u);
        g[u][v] = g[v][u] = true;
    }
    cin >> mh;
    rep(i, mh) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        // h[u].push_back(v);
        // h[v].push_back(u);
        h[u][v] = h[v][u] = true;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vec order(n);
    rep(i, n) order[i] = i;

    do {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(h[i][j] != g[order[i]][order[j]]) sum += a[i][j];
            }
        }
        ans = min(ans, sum);
    }while(next_permutation(all(order)));

    cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}