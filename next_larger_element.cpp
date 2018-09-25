/*
For a given value of n, the stack S contains all A[i]'s with i>=n
such that A[i]>=A[j] for all j>=i, sorted by decreasing values of A[i].
To compute the answer, we only have to look at the back of the stack.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), S, ans;
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    for(int n = N - 1; n >= 0; --n) {
        while(S.size() && S.back() <= A[n]) {
            S.pop_back();
        }
        ans.push_back((S.size()) ? (S.back()) : (-1));
        S.push_back(A[n]);
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
