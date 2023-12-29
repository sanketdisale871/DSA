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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){

                    int u = i*n+j;

                    int drow[]={-1,1,0,0};
                    int dcol[]={0,0,-1,1};

                    for(int itr=0;itr<4;itr++){
                        int newX = drow[itr]+i;
                        int newY = dcol[itr]+j;

                        if((newX>=0 && newX<n) && (newY>=0 && newY<n) && (grid[newX][newY]==1)){
                            int v = newX*n+newY;
                            ds.unionBySize(u,v);
                           
                        }
                    }
                }
            }
        }


        int area = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;

                    int drow[]={-1,1,0,0};
                    int dcol[]={0,0,-1,1};

                    for(int itr=0;itr<4;itr++){
                        int newX = drow[itr]+i;
                        int newY = dcol[itr]+j;

                        if((newX>=0 && newX<n) && (newY>=0 && newY<n) && (grid[newX][newY]==1)){
                            int v = newX*n+newY;

                           st.insert(ds.findUltPar(v));
                        }
                    }

                    int ar = 0;

                    for(auto it:st){
                        ar+=(ds.size[it]);
                    }

                    area = max(area,ar+1);
                }
            }
        }


        // If matrix not conatin the any 0 wala cell 
        for(int i=0;i<n*n;i++){
            area = max(area,ds.size[ds.findUltPar(i)]);
        }

        return area;
    }
};