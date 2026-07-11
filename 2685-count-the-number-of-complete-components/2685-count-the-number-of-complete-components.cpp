class Solution {
    void dfs(int curr, vector<vector<int>>& adj, vector<bool>& visited,
             vector<int>& component) {
        visited[curr] = true;
        component.push_back(curr);

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);
                int totalNodes = component.size();
                bool isComplete = true;

                for (int node : component) {
                    if (adj[node].size() != totalNodes - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    ans++;
                }
            }
        }

        return ans;
    }
};