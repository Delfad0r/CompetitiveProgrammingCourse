/*
For each index 0<=n<N, we want to compute F[n], the number of queries
n appears in. We do this by adding, for each query [l,r], +1 to F[l]
and -1 to F[r+1] and then computing prefix sums. Once we have done
that, we sort A and F. The answer is A[0]*F[0]+...+A[N-1]*F[N-1].
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    sort(A.begin(), A.end());
    vector<LL> F(N + 1, 0);
    while(Q--) {
        int l, r;
        cin >> l >> r;
        F[l - 1]++;
        F[r]--;
    }
    for(int n = 1; n <= N; ++n) {
        F[n] += F[n - 1];
    }
    F.pop_back();
    sort(F.begin(), F.end());
    LL ans = 0;
    for(int n = 0; n < N; ++n) {
        ans += A[n] * F[n];
    }
    cout << ans << '\n';
}
