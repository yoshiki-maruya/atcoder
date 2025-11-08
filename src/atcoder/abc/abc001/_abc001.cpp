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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int n, m, k;
	int ans = 0;
    vec a(n);
	vec b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[m];
	stack<int> sa;
	stack<int> sb;

	for(int i = n - 1;i >= 0; i--) {
		sa.push(a[i]);
	}
	for(int i = m - 1;i >= 0; i--) {
		sb.push(b[i]);
	}

	while(k > 0) {
		if (sa.top() > sb.top()) {
			k = k - sb.top();
			if (k < 0) break;
			sb.pop();
			ans++;
		}
		else {
			k = k - sa.top();
			if (k < 0) break;
			sa.pop();
			ans++;
		}
	}
	cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}