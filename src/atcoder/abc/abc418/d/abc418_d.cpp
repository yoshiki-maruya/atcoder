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
    int n;
    cin >> n;
    string t;
    cin >> t;

    vector<int> prefixOnes(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixOnes[i + 1] = prefixOnes[i] + (t[i] - '0');
    }

    ll totalBeautifulSubstrings = 0;
    ll counts[2] = {0, 0};

    counts[0] = 1;

    for (int k = 1; k <= n; ++k) {
        int currentVal = (k + prefixOnes[k]) % 2;
        totalBeautifulSubstrings += counts[currentVal];
        counts[currentVal]++;
    }

    cout << totalBeautifulSubstrings << endl;

    // ----------------------------------------------------------------
    return 0;
}