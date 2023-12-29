class DisjointSet{
    public:
    vector<int>size,parent;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i=0;i<n+1;i++){
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
        int ultp_u = findUltPar(u);
        int ultp_v = findUltPar(v);
        
        if(ultp_u==ultp_v){
           return;
        }
        
        if(size[ultp_u]<size[ultp_v]){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size[ultp_u];
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& st) {
        int maxRow = 0;
        int maxCol = 0;
        int n = st.size();
        for(int i=0;i<st.size();i++){
            maxRow = max(maxRow,st[i][0]);
            maxCol = max(maxCol,st[i][1]);
        }

        DisjointSet ds(maxRow+maxCol+1);

        for(auto it:st){
            int u = it[0];
            int v = maxRow+1+it[1];

            ds.unionBySize(u,v);
        }

        int compo = 0; // itne stone i can not remove

        for(int i=0;i<=(maxRow+maxCol+1);i++){
            if(i==ds.findUltPar(i)){

                if(ds.size[i]>1){
                    compo++;
                }
            }
        }

        return n-compo;
    }
};