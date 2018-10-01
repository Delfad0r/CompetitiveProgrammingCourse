/*
We build a binary array containing 1 at position n when S[n]==S[n-1],
and then compute prefix sums. Then answering the queries is trivial.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string S;
    cin >> S;
    int N = S.length();
    vector<int> P(N, 0);
    for(int n = 1; n < N; ++n) {
        P[n] = (S[n] == S[n - 1]) + P[n - 1];
    }
    int M;
    cin >> M;
    while(M--) {
        int l, r;
        cin >> l >> r;
        cout << (P[r - 1] - P[l - 1]) << '\n';
    }
}
