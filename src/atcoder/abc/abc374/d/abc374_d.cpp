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

struct Segment {
    double x1, y1, x2, y2;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double minTime(vector<Segment> &segments, double s, double t) {
    int n = segments.size();
    vector<int> order(n);
    iota(order.begin(), order.end(), 0); // {0, 1, ..., n-1}

    double min_time = DBL_MAX;

    // 全ての順列を試す
    do {
        // 各順列で、線分の方向も考慮するために全ての組み合わせを試す
        for (int mask = 0; mask < (1 << n); ++mask) {
            double time = 0.0;
            double curr_x = 0.0, curr_y = 0.0;

            for (int i = 0; i < n; ++i) {
                Segment &seg = segments[order[i]];
                double start_x, start_y, end_x, end_y;

                // maskの各ビットで線分の方向を決める
                if (mask & (1 << i)) {
                    start_x = seg.x2;
                    start_y = seg.y2;
                    end_x = seg.x1;
                    end_y = seg.y1;
                } else {
                    start_x = seg.x1;
                    start_y = seg.y1;
                    end_x = seg.x2;
                    end_y = seg.y2;
                }

                // 現在位置から線分の始点までの移動時間
                time += distance(curr_x, curr_y, start_x, start_y) / s;

                // レーザ照射時間
                time += distance(start_x, start_y, end_x, end_y) / t;

                // 現在位置を更新
                curr_x = end_x;
                curr_y = end_y;
            }

            // 最小時間の更新
            min_time = min(min_time, time);
        }
    } while (next_permutation(order.begin(), order.end()));

    return min_time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n;
    double s, t;
    cin >> n >> s >> t;

    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
    }

    double result = minTime(segments, s, t);

    cout << fixed << setprecision(20) << result << endl;

    // ----------------------------------------------------------------
    return 0;
}