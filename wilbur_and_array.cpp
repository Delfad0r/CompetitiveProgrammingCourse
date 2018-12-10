/*
We iterate over the array B and keep a counter incr, representing the
current value of the array at current position. The final value must
be B[i], so we add B[i]-incr to the current position; thus incr increases
by B[i]-incr, and the number of moves increases by abs(B[i]-incr). Note 
that we do not need to keep the whole array B in memory.

Time complexity:  O(N)
Space complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    long long ans = 0;
    int incr = 0;
    while(N--) {
        int b;
        cin >> b;
        ans += abs(b - incr);
        incr += b - incr;
    }
    cout << ans << '\n';
}
