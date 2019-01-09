/*
We follow a DP approach. dp(n,f,p) returns the minimum cardinality
of a vertex cover of the subtree rooted at n; f is true if node n
must be included in the cover, and p is the parent of node n (just
for convenience). dp is computed recursively with a DFS + memoization.

Time complexity:  O(N)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> G[100100];
int memo[100100][2];

int dp(int n, bool f, int p) {
	if(memo[n][f] >= 0) {
		return memo[n][f];
	}
	int sum0 = 0, sum1 = 0;
	for(int x : G[n]) {
		if(x != p) {
			sum0 += dp(x, false, n);
			sum1 += dp(x, true, n);
		}
	}
	if(f) {
		return memo[n][f] = 1 + sum0;
	} else {
		return memo[n][f] = min(1 + sum0, sum1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(memo, -1, sizeof(memo));
	
	int N;
	cin >> N;
	for(int n = 1; n < N; ++n) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	cout << dp(1, false, 0) << "\n";
	
	return 0;
}
