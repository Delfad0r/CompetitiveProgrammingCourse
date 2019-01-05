/*
We iterate from the end of the array to the beginning, keeping a stack S of
pairs (n, k) such that we can get to the end of the array with k jumps
starting from n. Additionally, we require that k-s are in decreasing order
(i.e. the top of the stack has the highest k). The stack is easy to update,
and each operation is O(1) amortized. At the end, the answer is stored on
the top of the stack.

Time complexity:  O(N)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int& a : A) {
        cin >> a;
    }
    vector<pair<int, int>> S = {make_pair(N - 1, 0)};
    for(int n = N - 2; n >= 0; --n) {
        while(S.size() >= 2 and n + A[n] >= S[S.size() - 2].first) {
            S.pop_back();
        }
        S.emplace_back(n, (A[n] > 0) ? (S.back().second + 1) : (1 << 30));
    }
    cout << ((S.back().second <= N) ? (S.back().second) : (-1)) << "\n";
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
