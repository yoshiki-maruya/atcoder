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

// 時計回りの距離を計算する関数
int clockwiseDistance(int from, int to, int n) {
    return (to - from + n) % n;
}

// 反時計回りの距離を計算する関数
int counterclockwiseDistance(int from, int to, int n) {
    return (from - to + n) % n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, q;
    cin >> n >> q;

    int leftHand = 1;  // 左手の初期位置
    int rightHand = 2; // 右手の初期位置
    int totalDistance = 0;

    for (int i = 0; i < q; i++) {
        char hand;
        int target;
        cin >> hand >> target;

        if (hand == 'L') {
            // 左手を動かす場合
            int clockwise = clockwiseDistance(leftHand, target, n);
            int counterclockwise = counterclockwiseDistance(leftHand, target, n);

            // 時計回りの経路に右手がある場合
            bool rightInClockwisePath = (clockwiseDistance(leftHand, rightHand, n) < clockwise);
            // 反時計回りの経路に右手がある場合
            bool rightInCounterclockwisePath = (counterclockwiseDistance(leftHand, rightHand, n) < counterclockwise);

            // 重ならないように動く
            if (!rightInClockwisePath) {
                totalDistance += clockwise;
                leftHand = target;
            } else if (!rightInCounterclockwisePath) {
                totalDistance += counterclockwise;
                leftHand = target;
            }
        } else if (hand == 'R') {
            // 右手を動かす場合
            int clockwise = clockwiseDistance(rightHand, target, n);
            int counterclockwise = counterclockwiseDistance(rightHand, target, n);

            // 時計回りの経路に左手がある場合
            bool leftInClockwisePath = (clockwiseDistance(rightHand, leftHand, n) < clockwise);
            // 反時計回りの経路に左手がある場合
            bool leftInCounterclockwisePath = (counterclockwiseDistance(rightHand, leftHand, n) < counterclockwise);

            // 重ならないように動く
            if (!leftInClockwisePath) {
                totalDistance += clockwise;
                rightHand = target;
            } else if (!leftInCounterclockwisePath) {
                totalDistance += counterclockwise;
                rightHand = target;
            }
        }
    }

    cout << totalDistance << endl;

    // ----------------------------------------------------------------
    return 0;
}