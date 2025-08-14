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
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        // 各チームから全勝できる選手の最大数を求める
        // 重要な観察：各チームから最大でも min(m, 他チーム数) 人しか全勝できない
        // なぜなら、他の各チームとの対戦で勝つ必要があるが、
        // 相手チームも同じ制約を持つから
        
        // より詳しく分析：
        // - 各チーム間でm人ずつ対戦
        // - チームiの選手がチームjに勝つ場合、チームjの選手はチームiに負ける
        // - 全体で最適化を考えると、できるだけ均等に勝利を分散させる
        
        // 最適解の考察：
        // 全勝者の総数をxとすると、各チームから最大 x/n 人（切り上げ）まで全勝可能
        // しかし、各チームは最大m人までしかいない
        // また、各対戦で勝者数の制約もある
        
        // より正確な分析：
        // 各チーム間の対戦でwin[i][j] = チームiがチームjに勝つ人数とする
        // win[i][j] + win[j][i] = m (各対戦でm人ずつ)
        // チームiから全勝する人数をx[i]とすると
        // x[i] <= win[i][j] for all j != i
        // つまり x[i] <= min(win[i][j] for all j != i)
        
        // 最適化問題：maximize sum(x[i]) subject to constraints
        // 対称性から、最適解では各チームから同じ人数が全勝する
        
        // 結論：各チームから最大 m/(n-1) 人（切り捨て）が全勝可能
        // なぜなら、チームiがチームjとの対戦で勝つ人数は最大mだが、
        // n-1個のチームと対戦するので、平均してm/(n-1)人ずつ勝つのが最適
        
        int maxWinnersPerTeam = m / (n - 1);
        int totalWinners = n * maxWinnersPerTeam;
        
        cout << totalWinners << "\n";
    }

    // ----------------------------------------------------------------
    return 0;
}