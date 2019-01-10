/*
At the n-th iteration, the deque Q contains all the indices i
(labelled with their values A[i]) in the range ]n-K,n] such that
A[i]>=A[j] for all j in ]i,n], sorted by decreasing values of A[i].
It can easily be proved by induction that the code produces
such a deque at each iteration. Consequently, the answer can be
obtained by simply looking at the back of the deque.

Time complexity:  O(N)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K;
    cin >> N>> K;
    deque<pair<int, int>> Q;
    for(int n = 0; n < N; ++n) {
        while(Q.size() && Q.back().second + K <= n) {
            Q.pop_back();
        }
        int a;
        cin >> a;
        while(Q.size() && Q.front().first <= a) {
            Q.pop_front();
        }
        Q.emplace_front(a, n);
        if(n + 1 >= K) {
            cout << Q.back().first << ' ';
        }
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
