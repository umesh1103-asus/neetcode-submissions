class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
        if(visited[node]) return;
        visited[node] = true;
        for (int i : adj[node]) dfs(i, adj, visited);   
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int count = 0;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int node=0;node<n;node++){
            if(!visited[node]){
                count++;
                dfs(node, adj, visited);
            }
        }
        return count;
    }

};
