#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to perform BFS and check if the graph is bipartite
bool isBipartite(vector<vector<int>>& graph, vector<int>& color, int start, long long& sizeA, long long& sizeB) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Color the starting node with 0
    sizeA = sizeB = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (color[node] == 0) sizeA++;
        else sizeB++;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node]; // Alternate the color
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false; // Graph is not bipartite
            }
        }
    }

    return true;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--; // Convert to 0-based indexing
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n, -1); // -1 means uncolored
        long long totalWays = 1;

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // New connected component
                long long sizeA = 0, sizeB = 0;
                if (!isBipartite(graph, color, i, sizeA, sizeB)) {
                    totalWays = 0; // If the graph is not bipartite
                    break;
                }
                long long ways = (modExp(2, sizeA, MOD) + modExp(2, sizeB, MOD)) % MOD;
                totalWays = (totalWays * ways) % MOD;
            }
        }

        cout << totalWays << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
