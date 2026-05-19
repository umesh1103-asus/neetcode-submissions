class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        queue<pair<int,pair<int,int>>> bfsQueue;

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]==2) bfsQueue.push({0, {i,j}});
            }
        }

        vector<int> dr = {1, 0 ,-1, 0};
        vector<int> dc = {0, 1, 0, -1};
        int ans = 0;

        while(!bfsQueue.empty()){
            pair<int, pair<int,int>> rottenIndex = bfsQueue.front();
            bfsQueue.pop();

            int t = rottenIndex.first;
            int r = rottenIndex.second.first;
            int c = rottenIndex.second.second;

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<ROW && nc>=0 && nc<COL 
                   && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    bfsQueue.push({t+1,{nr, nc}});
                    ans = max(ans, t+1);
                }
            }
        }

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]==1) return -1;
            }
        }  

        return ans;
    }
};
