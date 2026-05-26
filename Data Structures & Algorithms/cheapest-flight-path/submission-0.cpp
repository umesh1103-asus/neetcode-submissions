class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        } 
        
        vector<vector<int>> cost(n, vector<int>(k+2, 1e8));
        cost[src][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, src}); // cost, hops, node

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int c = curr[0];
            int hops = curr[1];
            int node = curr[2];

            if(node == dst) return c;
            if(hops == k+1) continue;
            if (c > cost[node][hops]) continue;

            for(auto d:adj[node]){
                if(cost[d[0]][hops+1] > c + d[1]) {
                    cost[d[0]][hops+1] = c + d[1];
                    pq.push({c + d[1], hops+1, d[0]});
                }
            }
        }

        return -1;
    }
};
