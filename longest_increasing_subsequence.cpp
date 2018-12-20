/*
We iterate over the numbers in the array. At the n-th step, V[i]
is the minimum possible value of the last element of an increasing
subsequence of length i using only the first n numbers.

Time complexity:  O(NlogN)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> V;
    while(N--) {
        int x;
        cin >> x;
        auto it = lower_bound(V.begin(), V.end(), x);
        if(it == V.end()) {
            V.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << V.size() << "\n";
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
