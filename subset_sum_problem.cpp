/*
We use a DP approach. To save space, we only keep one row of
the DP array. At the n-th iteration, dp[s] is 1 if we can get
a sum of s using only the first n numbers, 0 otherwise. At each
iteration, the array dp is scanned in reverse order to ensure
we don't use a number more than once. At the end, the answer
is yes if and only if dp[sum/2] is 1 (and sum is even).

Time complexity:  O(N*sum)
Space complexity: O(sum)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int sum = 0;
    vector<int> A(N);
    for(int& a : A) {
        cin >> a;
        sum += a;
    }
    if(sum & 1) {
        cout << "NO\n";
        return;
    }
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int a : A) {
        for(int s = sum - a; s >= 0; --s) {
            dp[a + s] |= dp[s];
        }
    }
    cout << ((dp[sum / 2]) ? ("YES\n") : ("NO\n"));
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
