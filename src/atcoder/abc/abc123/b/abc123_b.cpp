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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    vec x(5);
    int result = 0;
    rep(i, 5){
        cin >> x[i];
    }

    auto it = partition(x.begin(), x.end(), [](int a) {
        return a % 10 == 0;
    });

    // それ以外を10で割った余りが大きい順に並べ替える
    sort(it, x.end(), [](int a, int b) {
        return (a % 10) > (b % 10);
    });

    // for (int i : x) {
    //     cout << i << endl;
    // }

    rep(i, 5) {
        int diff = 0;
        if (x[i] % 10 != 0 && i != 4) {
            diff = 10 - x[i] % 10;
        }
        result += x[i] + diff;
    }

    cout << result << endl;

    // ----------------------------------------------------------------
    return 0;
}