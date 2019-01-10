/*
The solution is very straightforward: we simply sort the
string, then put the smallest even digit (if any) at the end;

Time complexity: O(NlogN)
Space complexity: O(N)

where N is the length of S.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    string last;
    for(int i = 0; i < int(S.length()); ++i) {
        if((S[i] - '0') % 2 == 0) {
            last += S[i];
            S.erase(i, 1);
            break;
        }
    }
    reverse(S.begin(), S.end());
    cout << S << last << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
