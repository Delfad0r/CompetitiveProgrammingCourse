/*
First we compute all the primes we may need with the sieve of
Eratosthenes (once for all testcases). Then we simply perform
a DFS on the tree (augmented with a dummy root 0 whose only
child is Mr. Alfred) keeping track of the depth and counting
the number of employees satisfying the condition.

Time complexity:  O(N)
Space complexity: O(N)

(excluding the computation of prime numbers)
*/

#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime;

void sieve(int N) {
    is_prime.assign(N, true);
    is_prime[0] = is_prime[1] = false;
    for(int p = 2; p * p < N; ++p) {
        if(is_prime[p]) {
            for(int q = p * p; q < N; q += p) {
                is_prime[q] = false;
            }
        }
    }
}

int dfs(const vector<vector<int>>& G, int n = 0, int d = -1) {
    int ans = 0;
    if(d > 0 and is_prime[n + d]) {
        ++ans;
    }
    for(int x : G[n]) {
        ans += dfs(G, x, d + 1);
    }
    return ans;
}

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> G(N + 1);
    for(int n = 1; n <= N; ++n) {
        int a;
        cin >> a;
        G[a].push_back(n);
    }
    cout << dfs(G) << '\n';
}

int main() {
    sieve(200200);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
