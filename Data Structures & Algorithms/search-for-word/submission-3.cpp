class Solution {
private:
    bool contains = false;
    void findWord(string word, int idx, int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board){
        int ROW = board.size();
        int COL = board[0].size();
        if(row<0 || row>=ROW || col<0 || col>=COL || contains || visited[row][col]) return;
        if(board[row][col] != word[idx]) return;
        if(idx==word.size()-1){
            contains = true;
            return;
        }
        
        visited[row][col] = true;
        findWord(word, idx+1, row+1, col, visited, board);
        findWord(word, idx+1, row-1, col, visited, board);
        findWord(word, idx+1, row, col+1, visited, board);
        findWord(word, idx+1, row, col-1, visited, board);
        visited[row][col] = false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROW = board.size();
        int COL = board[0].size();
        vector<vector<bool>> visited(COL, vector<bool>(ROW, false));
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++)
            {
                if(board[i][j]==word[0]){
                    findWord(word, 0, i, j, visited, board);
                }
                if(contains) return true;
            }
        }
        return false;
    }
};
