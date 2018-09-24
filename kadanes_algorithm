/*
We iterate on the array, keeping the current best answer (ans)
and the running sum (sum). For each element we update the running sum,
then update ans if necessary, and finally if
the running sum is negative we reset it to 0.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int ans = -(1 << 30), sum = 0;
    for(int n = 0; n < N; ++n) {
        int a;
        cin >> a;
        sum += a;
        ans = max(ans, sum);
        if(sum < 0) {
            sum = 0;
        }
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
