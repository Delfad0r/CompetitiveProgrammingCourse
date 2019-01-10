/*
For each connected component of the graph we run a DFS, coloring adjacent
vertices with different colors (1 or 2). If we find a contradiction (i.e.
a vertex we have already colored should have a different color) then the
graph is not bipartite, otherwise it is.

Time complexity:  O(N)
Space complexity: O(N)
*/

bool isBipartite(int G[][MAX], int V) {
    vector<int> color(V, 0);
    function<bool(int)> dfs = [&](int v) {
        for(int u = 0; u < V; ++u) {
            if(G[v][u]) {
                if(color[u] == color[v]) {
                    return false;
                } else if(color[u] == 0) {
                    color[u] = 3 - color[v];
                    if(not dfs(u)) {
                        return false;
                    }
                }
            }
        }
        return true;
    };
    for(int v = 0; v < V; ++v) {
        if(color[v] == 0) {
            color[v] = 1;
            if(not dfs(v)) {
                return false;
            }
        }
    }
    return true;
}
