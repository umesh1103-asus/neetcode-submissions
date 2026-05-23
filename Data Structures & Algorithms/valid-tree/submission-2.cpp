class DSU{
    vector<int> Parent, Size;
public:
    DSU(int n){
        Parent.resize(n);
        Size.resize(n);

        for(int i=0;i<n;i++){
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node){
        if(node != Parent[node]){
            Parent[node] = find(Parent[node]);
        }

        return Parent[node];
    }

    bool unionBySize(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);

        if(p1==p2) return false;
        if(Size[p1]>=Size[p2]){
            Size[p1] += Size[p2];
            Parent[p2] = p1;
        } else {
            Size[p2] += Size[p1];
            Parent[p1] = p2;
        }

        return true;
    }

    int getParent(int node){
        return find(node);
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto edge:edges){
            if(!dsu.unionBySize(edge[0], edge[1])) return false;
        }

        int rootCount = 0;
        for(int i=0;i<n;i++){
            if(dsu.getParent(i)==i) rootCount++;
        }

        return rootCount==1;
    }
};
