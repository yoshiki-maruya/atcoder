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

std::vector<int> processVector(const std::vector<int>& v) {
    std::vector<int> newVec = v;

    if (newVec.size() > 0) newVec[0] -= 1;
    if (newVec.size() > 1) newVec[1] -= 1;

    return newVec;
}

int countPositiveElements(const std::vector<int>& v) {
    return std::count_if(v.begin(), v.end(), [](int x) { return x > 0; });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n;
    int result = 0;

    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    while (countPositiveElements(a) > 1) {
        result++;
        sort(a.rbegin(), a.rend());
        a = processVector(a);
    }
    cout << result << endl;

    // ----------------------------------------------------------------
    return 0;
}