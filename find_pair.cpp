/*
We sort the input array A, and decrease K by 1 so that it is
consistent with 0-based indexing. Let a be A[K/N], u be the
number of entries in A equal to a, v the number of entries smaller
than a. Then the first element of the K-th pair is a, and the
second one is A[(K-v*N)/u].

Time complexity:  O(NlogN)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    long long K;
    cin >> N >> K;
    --K;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    sort(A.begin(), A.end());
    int a = A[K / N];
    long long u = 0, v = 0;
    for(int n = 0; n < N; ++n) {
        if(A[n] == a) {
            ++u;
        } else if(A[n] < a) {
            ++v;
        }
    }
    cout << a << ' ' << A[(K - v * N) / u] << '\n';
}
