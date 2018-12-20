/*
We use a DP approach. At each iteration we compute the maximum
value achievable with the first n objects using every weight
from 0 to W. To reduce space complexity we use a single array
of size W to store this value.

Time complexity:  O(NW)
Space complexity: O(N+W)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, W;
    cin >> N >> W;
    vector<int> ans(W + 1, 0);
    vector<int> WT(N), V(N);
    for(int& v : V) {
        cin >> v;
    }
    for(int& wt : WT) {
        cin >> wt;
    }
    for(int n = 0; n < N; ++n) {
        for(int i = W - WT[n]; i >= 0; --i) {
            ans[i + WT[n]] = max(ans[i + WT[n]], ans[i] + V[n]);
        }
    }
    cout << ans.back() << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
