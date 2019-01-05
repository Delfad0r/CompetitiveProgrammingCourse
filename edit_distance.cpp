/*
We implement the standard DP solution. The array dp[n][m] contains the
minimum number of moves to change S1[0..n-1] into S2[0..m-1]. After
taking care of the base cases, to compute dp[n][m] we consider two cases.
If S1[n-1]==S2[m-1] then dp[n][m] is simply dp[n-1][m-1] (the last letter
is already the right one). Otherwise we either remove, insert or change
at the end of S1[0..n-1], and use the previously computed values of dp.

Time complexity:  O(NM)
Space complexity: O(NM)

where N=length(S1), M=length(S2)
*/

#include <bits/stdc++.h>

using namespace std;

int dp[200][200];

void solve() {
    memset(dp, 0, sizeof(dp));
    int N, M;
    string S1, S2;
    cin >> N >> M >> S1 >> S2;
    for(int n = 0; n <= N; ++n) {
        dp[n][0] = n;
    }
    for(int m = 1; m <= M; ++m) {
        dp[0][m] = m;
        for(int n = 1; n <= N; ++n) {
            if(S1[n - 1] == S2[m - 1]) {
                dp[n][m] = dp[n - 1][m - 1];
            } else {
                dp[n][m] = min(dp[n - 1][m - 1] + 1,
                    min(dp[n - 1][m] + 1, dp[n][m - 1] + 1));
            }
        }
    }
    cout << dp[N][M] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
