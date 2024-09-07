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

int getDigit(ll n) {
  return to_string(n).length();
}

// 関数：使用する数字（3, 5, 7）を1つずつ含む全ての数を生成
void generateNumbers(vector<int>& digits, string current, int maxLength, int maxValue, int& count) {
    if (current.length() > 0) {
        // 文字列を数値に変換
        int number = stoi(current);
        if (number <= maxValue && current.find('3') != string::npos 
            && current.find('5') != string::npos 
            && current.find('7') != string::npos) {
            count++;
        }
    }

    // 数字が既に最大桁数に達している場合はこれ以上追加しない
    if (current.length() >= maxLength) {
        return;
    }

    // 各桁に3, 5, 7を追加して新たな数を生成
    for (int digit : digits) {
        generateNumbers(digits, current + to_string(digit), maxLength, maxValue, count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int maxValue;
    cin >> maxValue;  // 入力された値を取得
    
    vector<int> digits = {3, 5, 7};  // 使用する数字
    int count = 0;
    
    // 入力された値の桁数
    int maxLength = to_string(maxValue).length();
    
    // 数字を生成しカウント
    generateNumbers(digits, "", maxLength, maxValue, count);
    
    // 結果を出力
    cout << count << endl;

    // ----------------------------------------------------------------
    return 0;
}