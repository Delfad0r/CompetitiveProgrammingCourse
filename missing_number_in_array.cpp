/*
The missing number is equal to
N*(N+1)
------- - (sum of the other numbers)
   2
as the sum of all numbers from 1 to N is N*(N+1)/2.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
    LL N;
    cin >> N;
    LL ans = N * (N + 1) / 2;
    while(--N) {
        LL a;
        cin >> a;
        ans -= a;
    }
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
