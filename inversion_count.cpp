/*
We implement an algorithm similar to merge sort. In the merge step,
in addition to sorting the sequence, we also compute the number of
inversions between elements of A2 and elements of A1 (i.e. the sum
for a2 in A2 of the number of elements in A1 that are larger than a2).

Time complexity:  O(NlogN)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL count_inversions(vector<int>& A) {
	int m = A.size() / 2;
	if(m == 0) {
		return 0;
	}
	vector<int> A1(A.begin(), A.begin() + m), 
		A2(A.begin() + m, A.end());
	A.clear();
	LL ans = count_inversions(A1) + count_inversions(A2);
	int m1 = A1.size(), m2 = A2.size();
	for(int i1 = 0, i2 = 0; i1 < m1 or i2 < m2; ) {
		if(i1 >= m1 or (i2 < m2 and A1[i1] > A2[i2])) {
			A.push_back(A2[i2++]);
			ans += m1 - i1;
		} else {
			A.push_back(A1[i1++]);
		}
	}
	return ans;
}

void solve() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int n = 0; n < N; ++n) {
		cin >> A[n];
	}
	cout << count_inversions(A) << '\n';
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
