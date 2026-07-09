class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;

    DisjointSet(int siz){
        size.resize(siz+1,1);
        parent.resize(siz+1);

        for(int i=0;i<=siz;i++){
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
            return;
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n+1);

        for(int i=1;i<n;i++){
            int diff = nums[i]-nums[i-1];

            if(diff<=maxDiff){
                ds.unionBySize(i-1,i);
            }
        }

        vector<bool>ans;

        for(auto it:queries){
            int ult_u = ds.findUltPar(it[0]);
            int ult_v = ds.findUltPar(it[1]);

            if(ult_u==ult_v){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};