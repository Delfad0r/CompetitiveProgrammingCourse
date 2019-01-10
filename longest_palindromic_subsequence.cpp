/*
The longest palindromic subsequence of a string S is simply the
longest common subsequence of S and the reverse of S.

Time complexity:  O(N^2)
Space complexity: O(N^2)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S, Z;
    cin >> S;
    Z = S;
    reverse(Z.begin(), Z.end());
    int N = S.size();
    vector<vector<int>> lcs(N + 1, vector<int>(N + 1, 0));
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < N; ++m) {
            lcs[n + 1][m + 1] =
                (S[n] == Z[m])
                ? (1 + lcs[n][m])
                : (max(lcs[n][m + 1], lcs[n + 1][m]));
        }
    }
    cout << lcs[N][N] << "\n";
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
