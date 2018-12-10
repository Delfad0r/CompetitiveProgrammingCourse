/*
We sort the meetings by finish time F, then we greedily select
the first available meeting that does not overlap with any of
the previously selected ones.

Time complexity:  O(NlogN)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> S(N), F(N), idx(N);
    iota(idx.begin(), idx.end(), 0);
    for(int i : idx) {
        cin >> S[i];
    }
    for(int i : idx) {
        cin >> F[i];
    }
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return F[i] < F[j];
    });
    int t = 0;
    for(int i : idx) {
        if(S[i] > t) {
            cout << i + 1 << ' ';
            t = F[i];
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
