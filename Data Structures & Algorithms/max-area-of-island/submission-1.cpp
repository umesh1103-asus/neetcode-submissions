class Solution {
private:
    int maxArea;
    void dfs(int row, int col, int& area, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int ROW = grid.size();
        int COL = grid[0].size();
        if(row<0 || col<0 || row>=ROW || col>=COL || visited[row][col] || grid[row][col]==0) {
            maxArea = max(area, maxArea);
            return;
        }

        visited[row][col] = true;
        area++;
        dfs(row+1, col, area, grid, visited);
        dfs(row-1, col, area, grid, visited);
        dfs(row, col+1, area, grid, visited);
        dfs(row, col-1, area, grid, visited);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxArea = 0;
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]==1) {
                    int area = 0;
                    dfs(i, j, area, grid, visited);
                }
            }
        }

        return maxArea;
    }
};
