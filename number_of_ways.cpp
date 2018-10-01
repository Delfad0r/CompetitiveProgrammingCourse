/*
A[n] stores the prefix sum of the sequence of indices from 0
up to n-1. Then we count for each 1<=n<N such that A[n]==2*A[N]/3
the number of indices m<n such that A[m]==A[N]/3 (this means we
can split the sequence at indices m and n).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    for(int n = 1; n <= N; ++n) {
        cin >> A[n];
        A[n] += A[n - 1];
    }
    long long ans = 0;
    for(int n = 1, k = 0; n < N; ++n) {
        if(A[n] * 3 == A[N] * 2) {
            ans += k;
        }
        if(A[n] * 3 == A[N]) {
            ++k;
        }
    }
    cout << ans << '\n';
}
