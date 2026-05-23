class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) {
        Parent.resize(n+1);
        Size.resize(n+1);

        for(int i=0;i<=n;i++){
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node){
        if(node!=Parent[node]){
            Parent[node] = find(Parent[node]);
        }

        return Parent[node];
    }

    bool unionBySize(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);

        if(p1==p2) return false;
        if(Size[p1]>=Size[p2]){
            Parent[p2] = p1;
            Size[p1] += Size[p2];
        } else{
            Parent[p1] = p2;
            Size[p2] += Size[p1];
        }

        return true;
    }

    int getSize(int node) {
        return Size[find(node)];
    }
};

class Solution {
private:
    int index(int r, int c, int COL){
        return r*COL + c;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int area = 0;

        DSU dsu(ROW*COL);

        vector<vector<int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(grid[r][c]==1){
                    for(int k=0;k<4;k++){
                        int nr = r + dr[k][0];
                        int nc = c + dr[k][1];

                        if(nr>=0 && nr<ROW && nc>=0 && nc<COL && grid[nr][nc]==1){
                            dsu.unionBySize(index(r, c, COL), index(nr, nc, COL));
                        }
                    }
                    area = max(area, dsu.getSize(index(r, c, COL)));
                }
            }
        }

        return area;
    }
};
