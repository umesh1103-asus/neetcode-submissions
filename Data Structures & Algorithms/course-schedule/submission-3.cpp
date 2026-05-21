class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        for(auto dep:prerequisites) adj[dep[1]].push_back(dep[0]);
        for(int i=0;i<n;i++){
            for(auto next:adj[i]) indegree[next]++;
        }

        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        if(q.empty()) return false;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int next:adj[front]){
                if(indegree[next]==0) return false;
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }

        for(int x:indegree) if(x!=0) return false;
        return true;
        //return q.empty();
    }
};
