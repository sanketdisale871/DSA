class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
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
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int qSize = queries.size();
        vector<int>ans(qSize);

        vector<vector<int>>nodeVals;
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nodeVals.push_back({grid[i][j],i,j});
            }
        }

        sort(nodeVals.begin(),nodeVals.end());

        vector<pair<int,int>>qVals;

        for(int i=0;i<qSize;i++){
            qVals.push_back({queries[i],i});
        }

        sort(qVals.begin(),qVals.end());

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,1,-1};

        int ind = 0;

        DisjointSet ds(m*n+5);

        for(auto it:qVals){
            while(ind<m*n && it.first > nodeVals[ind][0]){
                int r = nodeVals[ind][1],c = nodeVals[ind][2];
                vis[r][c]=1;

                for(int i=0;i<4;i++){
                    int newX = drow[i]+r;
                    int newY = dcol[i]+c;

                    if((newX>=0 && newX<m) && (newY>=0 && newY<n) && vis[newX][newY]){
                        int u = r*n+c;
                        int v = newX*n + newY;

                        ds.unionBySize(u,v);
                    }
                }
                ind++;
            }

            if(vis[0][0]){
                ans[it.second]=ds.size[ds.findUltPar(0)];
            }
        }


        return ans;
    }
};