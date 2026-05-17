class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int ROW = grid.size();
        int COL = grid[0].size();
        if(row<0 || col<0 || row>=ROW || col>=COL || visited[row][col] || grid[row][col]=='0') return;
        visited[row][col] = true;
        dfs(row+1, col, grid, visited);
        dfs(row-1, col, grid, visited);
        dfs(row, col+1, grid, visited);
        dfs(row, col-1, grid, visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        int islandCount = 0;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    islandCount++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return islandCount;
    }
};
