class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROW = board.size();
        int COL = board[0].size();

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        queue<pair<int,int>> que;
        
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for(int i=0;i<ROW;i++){
            if(board[i][0]=='O') {
                que.push({i, 0});
                visited[i][0]=true;
            }
            if(board[i][COL-1]=='O') {
                que.push({i, COL-1});
                visited[i][COL-1]=true;
            }
        }

        for(int j=0;j<COL;j++){
            if(board[0][j]=='O') {
                que.push({0, j});
                visited[0][j]=true;
            }
            if(board[ROW-1][j]=='O') {
                que.push({ROW-1, j});
                visited[ROW-1][j]=true;
            }
        }

        while(!que.empty()){
            auto [r, c] = que.front();
            que.pop();

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<ROW && nc<COL && !visited[nr][nc]){
                    if(board[nr][nc]=='O') {
                        visited[nr][nc] = true;
                        que.push({nr, nc});
                    }
                }
            }
        }

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(!visited[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
