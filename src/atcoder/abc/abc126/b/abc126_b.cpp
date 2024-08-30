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
    string s; cin >> s;
    if ((stoi(s.substr(0, 2)) >= 1 && stoi(s.substr(0, 2)) <= 12) && (stoi(s.substr(2, 4)) >= 1 && stoi(s.substr(2, 4)) <= 12)){
        cout << "AMBIGUOUS" << endl;
    }
    else if ((stoi(s.substr(0, 2)) > 12 && stoi(s.substr(2, 4)) <= 12 && stoi(s.substr(2, 4)) >= 1)
    || (stoi(s.substr(2, 4)) <= 12 && stoi(s.substr(2, 4)) >= 1 && stoi(s.substr(0, 2)) == 0)){
        cout << "YYMM" << endl;
    }
    else if ((stoi(s.substr(2, 4)) > 12 && stoi(s.substr(0, 2)) <= 12 && stoi(s.substr(0, 2)) >= 1)
    || (stoi(s.substr(0, 2)) <= 12 && stoi(s.substr(0, 2)) >= 1 && stoi(s.substr(2, 4)) == 0)) {
        cout << "MMYY" << endl;
    }
    else {
        cout << "NA" << endl;
    }
    // ----------------------------------------------------------------
    return 0;
}