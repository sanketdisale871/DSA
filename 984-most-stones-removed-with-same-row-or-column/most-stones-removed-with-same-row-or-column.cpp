class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }

    int findUltPar(int node){

        if(parent[node]==node){
            return node;
        }

        return parent[node]=findUltPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ult_u = findUltPar(u);
        int ult_v = findUltPar(v);

        if(ult_u == ult_v){
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto it:stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }

        DisjointSet ds(maxRow + maxCol+2);

        for(auto it:stones){
            int u = it[0];
            int v = it[1]+maxRow + 1;

            cout<<"u : "<<u<<" v : "<<v<<endl;

            ds.unionBySize(u,v);
        }
        int cnt = 0;

        for(int i=0;i<=maxRow+maxCol+1;i++){
            cout<<"i "<<i<<" parent [ i ] : "<<ds.parent[i]<<endl;
            if(ds.findUltPar(i)==i){
                if(ds.size[i]>1){

                cnt++;
                }
            }
        }

        return stones.size()-cnt;
    }
};