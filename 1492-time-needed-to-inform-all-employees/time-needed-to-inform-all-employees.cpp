class Solution {
public:

    int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime) {

        int maxTime = 0;

        for (int child : adj[node]) {

            int time = dfs(child, adj, informTime);

            maxTime = max(maxTime, time);
        }

        return informTime[node] + maxTime;
    }

    int numOfMinutes(int n, int headID,
                     vector<int>& manager,
                     vector<int>& informTime) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {

            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        // Start DFS from head
        return dfs(headID, adj, informTime);
    }
};