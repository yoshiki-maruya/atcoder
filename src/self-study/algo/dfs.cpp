#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(Graph &g, int v) {
	seen[v] = true;

	for(auto next : g[v]) {
		if (seen[next]) continue;
		cout << next << endl;
		dfs(g, next);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	Graph g(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	seen.assign(n, false);
	dfs(g, 0);
}