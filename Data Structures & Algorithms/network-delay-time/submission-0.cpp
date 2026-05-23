class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:times) adj[edge[0]].push_back({edge[2], edge[1]});
        vector<int> visited(n+1, false);
        int delay = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if (visited[node]) continue;
            delay = max(delay, time);

            visited[node] = true;
            for(auto next:adj[node]){
                if(!visited[next.second]) pq.push({time+next.first, next.second});
            }
        }
        for(int i=1;i<=n;i++) if(!visited[i]) return -1;
        return delay;
    }
};
