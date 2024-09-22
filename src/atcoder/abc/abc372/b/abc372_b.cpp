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

int powerOfThree(int exponent) {
    if (exponent < 0 || exponent > 11) {
        cout << "指数は0から10までの範囲で指定してください。" << endl;
        return -1;
    }
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 3;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int m;
    cin >> m;
    int n = 0;
    vec a(n);
    vec three(100);
    for (int i = 0; i <= 11; i++) {
        three[i] = powerOfThree(i);
    }

    while(true) {
        if(m == 0) break;

        for(int i = 0; i <= 11; i++) {
            int t = three[i];
            if(m < t || i == 11) {
                m -= three[i - 1];
                n++;
                a.push_back(i - 1);
                break;
            }
        }
    }
    cout << n << endl;
    for (int i = 0; i < a.size(); i++) {
        if(i == a.size() - 1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;

    // ----------------------------------------------------------------
    return 0;
}