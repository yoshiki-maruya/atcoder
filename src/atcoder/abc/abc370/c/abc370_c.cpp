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

#define irep(i, n) for (int i = (int)n; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/

#define INF INT_MAX
#define LINF LLONG_MAX

char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
}

int alphabet_to_int(char s) {
    return s - 'a';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    int changeCount = 0;
    vector<string> history;

    rep(i, n) {
        //cout << s[i] << ":" << alphabet_to_int(s[i]) << " " << t[i] << ":" << alphabet_to_int(t[i]) << endl;
        if (s[i] != t[i] && alphabet_to_int(s[i]) > alphabet_to_int(t[i])) {
            s[i] = t[i];
            changeCount++;
            history.push_back(s);
        }
    }
    irep(i, n) {
        if (s[i] != t[i] && alphabet_to_int(s[i]) < alphabet_to_int(t[i])) {
            s[i] = t[i];
            changeCount++;
            history.push_back(s);
        }
    }


    // 書き換えにかかった回数を出力
    cout << changeCount << endl;
    for (const string& str : history) {
        cout << str << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}