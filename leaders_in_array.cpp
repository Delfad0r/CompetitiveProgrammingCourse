/*
We iterate from the end of the array to the beginning keeping
the maximum value encountered so far (m, initially -1);
when an element >= m is found, it is marked as a leader and m is updated.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    vector<int> ans;
    for(int n = N - 1, m = -1; n >= 0; --n) {
        if(A[n] >= m) {
            ans.push_back(m = A[n]);
        }
    }
    while(ans.size()) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    cout << '\n';
}

int main() {
	int T;
	cin >> T;
	while(T--) {
	    solve();
	}
}
