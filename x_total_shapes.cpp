/*
We have to count the number of connected components of the graph
whose vertices are the X's and adjacent X's are connected. To
achieve this we simply iterate over all X's and run a DFS when
we encounter one we haven't visited yet, incrementing the counter
by one.
*/

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> G(N);
    for(auto& s : G) {
        cin >> s;
    }
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    function<void(int, int)> dfs = [&](int x, int y) {
        visited[y][x] = true;
        for(int i = 0; i < 4; ++i) {
            int x1 = x + dx[i], y1 = y + dy[i];
            if(x1 >= 0 and x1 < M and y1 >= 0 and y1 < N
                and (not visited[y1][x1]) and G[y1][x1] == 'X') {
                    dfs(x1, y1);
            }
        }
    };
    int ans = 0;
    for(int x = 0; x < M; ++x) {
        for(int y = 0; y < N; ++y) {
            if((not visited[y][x]) and G[y][x] == 'X') {
                ++ans;
                dfs(x, y);
            }
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
