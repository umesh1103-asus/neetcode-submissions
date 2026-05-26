class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        if(ROWS==0) return 0;
        int COLS = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        pq.push({grid[0][0],0,0});

        vector<vector<int>> dr = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            
            int t = top[0];
            int r = top[1];
            int c = top[2];

            if(visited[r][c]) continue;
            visited[r][c] = true;

            for(auto d:dr){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr>=0 && nr<ROWS && nc>=0 && nc<COLS && !visited[nr][nc]){
                    grid[nr][nc] = max(t,grid[nr][nc]);
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }

        return grid[ROWS-1][COLS-1];
    }
};
