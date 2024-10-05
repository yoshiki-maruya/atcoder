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

bool isAllDigitsSame(const string& s) {
    return s[0] == s[1] && s[1] == s[2] && s[2] == s[3];
}

bool isThreeConsecutive(const string& s) {
    for (int i = 0; i < 3; ++i) {
        if ((s[i] - '0' + 1) % 10 != (s[i + 1] - '0')) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
        cout << "Weak" << endl;
        return 0;
    }

    if((s[0] - '0' + 1) % 10 == s[1] - '0' && (s[1] - '0' + 1) % 10 == s[2] - '0' && (s[2] - '0' + 1) % 10 == s[3] - '0') {
        cout << "Weak" << endl;
        return 0;
    }

    cout << "Strong" << endl;

    // ----------------------------------------------------------------
    return 0;
}