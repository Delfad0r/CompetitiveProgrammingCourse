/*
We simply implement the KMP algorithm.

Time complexity:  O(N)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    vector<int> P(S.length(), 0);
    for(int k = 0, i = 1; i < int(S.length()); ++i) {
        while(k > 0 and S[i] != S[k]) {
            k = P[k - 1];
        }
        if(S[i] == S[k]) {
            ++k;
        }
        P[i] = k;
    }
    cout << P.back() << "\n";
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
