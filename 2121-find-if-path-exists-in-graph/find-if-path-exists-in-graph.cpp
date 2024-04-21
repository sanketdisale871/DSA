class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUltPar(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node]=findUltPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ult_u =findUltPar(u); 
        int ult_v =findUltPar(v); 

        if(ult_u==ult_v){
            return ;
        }

        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            parent[ult_u]=ult_v;
        }
        else{
            size[ult_u]+=size[ult_v];
            parent[ult_v]=ult_u;
        }
    }

};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);

        for(auto it:edges){
            ds.unionBySize(ds.findUltPar(it[0]),ds.findUltPar(it[1]));
        }

        return ds.findUltPar(source)==ds.findUltPar(destination);
    }
};