/*
We start with an array A containing N+1 zeros. To process query
(l,r,v) we add +v to A[l] and add -v to A[r+1]. After that we
compute prefix sums, and the array A is correctly updated. Then
answering the queries is trivial (we simply print the value of
A at the requested index).
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N, U;
	cin >> N >> U;
	vector<int> A(N + 1, 0);
	while(U--) {
		int l, r, v;
		cin >> l >> r >> v;
		A[l] += v;
		A[r + 1] -= v;
	}
	for(int n = 1; n <= N; ++n) {
		A[n] += A[n - 1];
	}
	int Q;
	cin >> Q;
	while(Q--) {
		int n;
		cin >> n;
		cout << A[n] << '\n';
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
