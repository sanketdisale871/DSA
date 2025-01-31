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
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findUltPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ult_u = findUltPar(u);
        int ult_v = findUltPar(v);

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
    int largestIsland(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>>vis(m,vector<int>(n,0));

            DisjointSet ds(m*n+1);

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1 && !vis[i][j]){
                        queue<pair<int,int>>q;
                        q.push({i,j});

                        vis[i][j]=1;


                        while(!q.empty()){
                            auto it = q.front();q.pop();
                            int x = it.first;
                            int y = it.second;

                            int drow[]={-1,1,0,0};
                            int dcol[]={0,0,1,-1};

                            for(int i=0;i<4;i++){
                                int newX = drow[i]+x;
                                int newY = dcol[i]+y;

                                if(newX>=0 && newX<m && newY>=0 && newY<n && !vis[newX][newY] && grid[newX][newY]){
                                    int u = x*n+y;
                                    int v = newX*n+newY;

                                    ds.unionBySize(u,v);

                                    q.push({newX,newY});
                                    vis[newX][newY]=1;
                                }
                            }
                        }
                    }
                }
            }  

            int maxArea = ds.size[0];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0){
                        unordered_set<int>st;

                        int drow[]={-1,1,0,0};
                        int dcol[]={0,0,1,-1};

                        for(int itr=0;itr<4;itr++){
                            int newX = drow[itr]+i;
                            int newY = dcol[itr]+j;

                            if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]){
                                st.insert(ds.findUltPar(newX*m+newY));
                            }
                        }

                        int ar=0;

                        for(auto it:st){
                            ar+=ds.size[it];
                        }
                        maxArea = max(maxArea,ar+1);
                    }
                }
            }
            return maxArea;   
    }
};