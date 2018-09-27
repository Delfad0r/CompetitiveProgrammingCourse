/*
We keep a stack S of nodes and a node u. At each iteration
we are in the left subtrees of nodes in S and in the right
subtree of node u. if a<u then we have reached a contradiction,
and there is no valid BST; Otherwise we update S and u.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> S;
    int u = 0;
    while(N--) {
        int a;
        cin >> a;
        if(a < u) {
            cout << 0 << '\n';
            while(N--) {
                cin >> a;
            }
            return;
        }
        while(S.size() and a > S.back()) {
            u = max(u, S.back());
            S.pop_back();
        }
        S.push_back(a);
    }
    cout << 1 << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
