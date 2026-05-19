class Solution {
public:
    const int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        queue<pair<int, int>> q;

        // Enqueue all treasure chests (0)
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            int dist = grid[r][c];

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL &&
                    grid[nr][nc] == INF) {
                    grid[nr][nc] = dist + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
