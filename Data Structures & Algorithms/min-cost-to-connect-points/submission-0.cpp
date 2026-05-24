class DSU {
public:
    vector<int> Parent, Size;

    DSU(int n){
        Parent.resize(n);
        Size.resize(n);

        for(int i=0;i<n;i++){
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node){
        if(Parent[node]!=node){
            Parent[node] = find(Parent[Parent[node]]);
        }

        return Parent[node];
    }

    bool unionBySize(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);

        if(p1==p2) return true;
        if(Size[p1]>=Size[p2]){
            Size[p1] += Size[p2];
            Parent[p2] = p1;
        } else {
            Size[p2] += Size[p1];
            Parent[p1] = p2;
        }

        return false;
    }
};

class Solution {
public:
    bool comparator(vector<vector<int>> a, vector<vector<int>> b){
        return a[0] < b[0];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<vector<int>> edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> p1 = points[i];
                vector<int> p2 = points[j];

                int dis = abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
                edges.push_back({dis, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cost = 0;
        int count = 0;

        for(auto edge:edges){
            if(!dsu.unionBySize(edge[1], edge[2])){
                cost+=edge[0];
                if(++count==n-1) break;
            }
        }

        return cost;
    }
};
