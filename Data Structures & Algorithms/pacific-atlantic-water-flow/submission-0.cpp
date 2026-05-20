class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROW = heights.size();
        int COL = heights[0].size();

        vector<vector<bool>> pac(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atl(ROW, vector<bool>(COL, false));

        stack<pair<int,int>> st;

        for(int i=0; i<ROW; i++) {
            pac[i][0] = true;
            st.push({i, 0});
        }

        for(int j=0; j<COL; j++) {
            pac[0][j] = true;
            st.push({0, j});
        }

        vector<int> dr = {1, 0 ,-1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!st.empty()){
            auto [r, c] = st.top();
            st.pop();

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<ROW && nc<COL && !pac[nr][nc] && heights[nr][nc]>= heights[r][c]){
                    pac[nr][nc] = true;
                    st.push({nr, nc});
                }
            }
        }

        for(int i=0; i<ROW; i++) {
            atl[i][COL-1] = true;
            st.push({i, COL-1});
        }

        for(int j=0; j<COL; j++) {
            atl[ROW-1][j] = true;
            st.push({ROW-1, j});
        }

        while(!st.empty()){
            auto [r, c] = st.top();
            st.pop();

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<ROW && nc<COL && !atl[nr][nc] && heights[nr][nc]>= heights[r][c]){
                    atl[nr][nc] = true;
                    st.push({nr, nc});
                }
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};
