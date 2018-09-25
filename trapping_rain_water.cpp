/*
The function f recursively computes the answer for the segment [b,e].
If b== e then there is no water trapped, and we return 0.
Otherwise, assume H[b]<=H[e] (the other case is identical).
Let i be the first index >=b such that H[i]>H[b].
Then we can easily compute the water trapped in [b,i],
and then call f on the segment [i,e]. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int H[10000000];

LL f(int b, int e) {
    if(b == e) {
        return 0;
    }
    LL ans = 0;
    int i;
    if(H[b] <= H[e]) {
        for(i = b; i < e && H[i] <= H[b]; ++i) {
            ans += H[b] - H[i];
        }
        return ans + f(i, e);
    } else {
        for(i = e; i > b && H[i] <= H[e]; --i) {
            ans += H[e] - H[i];
        }
        return ans + f(b, i);
    }
}

void solve() {
    int N;
    cin >> N;
    for(int n = 0; n < N; ++n) {
        cin >> H[n];
    }
    cout << f(0, N - 1) << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
