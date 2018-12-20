/*
We use a standard DP approach. lcs[n][m] is the longest common
subsequence of strings S[0..n-1] and Z[0..m-1]. If S[n]==Z[m],
then lcs[n+1][m+1]=1+lcs[n][m], otherwise it is the maximum
between lcs[n+1][m] and lcs[n][m+1].

Time complexity:  O(NM)
Space complexity: O(NM)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    string S, Z;
    cin >> N >> M >> S >> Z;
    vector<vector<int>> lcs(N + 1, vector<int>(M + 1, 0));
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            lcs[n + 1][m + 1] =
                (S[n] == Z[m])
                ? (1 + lcs[n][m])
                : (max(lcs[n][m + 1], lcs[n + 1][m]));
        }
    }
    cout << lcs[N][M] << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
