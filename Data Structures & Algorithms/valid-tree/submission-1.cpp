class Solution {
private:
    bool isCyclic(int node, vector<vector<int>> &adj, vector<bool> &visited, int parent){
        visited[node] = true;
        for (int i : adj[node])
        {
            if (!visited[i])
            {
                if (isCyclic(i, adj, visited, node))
                    return true;
            }
            else if(i != parent)
                return true;
        }

        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(isCyclic(0, adj, visited, -1))
            return false;

        for(bool visit:visited) if(!visit) return false;

        return true;
    }
};
