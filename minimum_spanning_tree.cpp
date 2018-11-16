/*
This solution implements Kruskal's algorithm for finding a MST.
*/

#include <bits/stdc++.h>

using namespace std;

class DSU {
	vector<int> f;
public:
	DSU(int n) : f(n) {
		iota(f.begin(), f.end(), 0);
	}
	int find_(int u) {
		return (f[u] == u) ? (u) : (f[u] = find_(f[u]));
	}
	bool union_(int u, int v) {
		u = find_(u);
		v = find_(v);
		if(u == v) {
			return false;
		}
		f[v] = u;
		return true;
	}
};

struct edge_t {
	int u, v;
	long long c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	DSU d(N);
	vector<edge_t> E;
	while(M--) {
		int u, v, c;
		cin >> u >> v >> c;
		E.push_back(edge_t{u - 1, v - 1, c});
	}
	sort(E.begin(), E.end(), [](edge_t& a, edge_t& b) { return a.c < b.c; });
	long long ans = 0;
	for(auto& e : E) {
		if(d.union_(e.u, e.v)) {
			ans += e.c;
		}
	}
	cout << ans << '\n';
}
