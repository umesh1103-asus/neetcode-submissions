class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node){
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionBySize(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);

        if(p1==p2) return false;
        if(size[p1]>=size[p2]){
            parent[p2] = p1;
            size[p1]+=size[p2];
        }
        else{
            parent[p1] = p2;
            size[p2]+=size[p1];
        }

        return true;
    }
};

class Solution {
public:
    int index(int row, int col, int COL){
        return row*COL + col;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>> dr = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        int islandCount = 0;
        DSU dsu(ROW*COL);


        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(grid[r][c]=='1'){
                    islandCount++;
                    for(auto d:dr){
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr>=0 && nc>=0 && nr<ROW && nc<COL && grid[nr][nc] == '1' && dsu.unionBySize(index(r, c, COL), index(nr, nc, COL))) islandCount--;
                    }
                }
            }
        }

        return islandCount;
    }
};
