class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> courseOrder;

        for(auto dep:prerequisites) adj[dep[1]].push_back(dep[0]);
        for(int i=0;i<n;i++){
            for(auto next:adj[i]) indegree[next]++;
        }

        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);

        while(!q.empty()){
            int front = q.front();
            q.pop();
            courseOrder.push_back(front);
            for(int next:adj[front]){
                //if(indegree[next]==0) return {};
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }

        for(int i:indegree) if(i>0) return {};
        return courseOrder;
    }
};
