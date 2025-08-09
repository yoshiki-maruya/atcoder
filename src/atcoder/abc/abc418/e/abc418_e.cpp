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

struct Point {
    ll x;
    ll y;
};

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

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    map<pair<ll, ll>, int> slopeCounts;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll dy = points[j].y - points[i].y;
            ll dx = points[j].x - points[i].x;

            ll commonDivisor = gcd(abs(dy), abs(dx));
            dy /= commonDivisor;
            dx /= commonDivisor;
            
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0 && dy < 0) {
                dy = -dy;
            }
            
            slopeCounts[{dy, dx}]++;
        }
    }

    ll totalCandidates = 0;
    for (auto const& [slope, count] : slopeCounts) {
        totalCandidates += (ll)count * (count - 1) / 2;
    }

    map<pair<ll, ll>, int> midpointCounts;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll xSum = points[i].x + points[j].x;
            ll ySum = points[i].y + points[j].y;
            midpointCounts[{xSum, ySum}]++;
        }
    }

    ll numParallelograms = 0;
    for (auto const& [midpoint, count] : midpointCounts) {
        numParallelograms += (ll)count * (count - 1) / 2;
    }

    ll result = totalCandidates - numParallelograms;

    cout << result << endl;

    // ----------------------------------------------------------------
    return 0;
}