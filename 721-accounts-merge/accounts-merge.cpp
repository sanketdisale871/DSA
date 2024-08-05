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
            return parent[node];
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accn) {
        
        // cout<<"Ram Krishna Hari!!"<<endl;

        /*
        Problem Explanation : 
        -> Name, Mail Id given
        -> If mail id same, that person and that have in same mail id
        -> Person => All mail IDs

        -- How i am looking : 
        -> Accordin gmail id indexing karata, 
        -> unko bad mai merge karta.        
        
        */
        int n = accn.size();

        DisjointSet ds(n+1);

        unordered_map<string,int>um;

        for(int i=0;i<accn.size();i++){
            for(int j=1;j<accn[i].size();j++){
                if(um.find(accn[i][j])!=um.end()){
                    int v = um[accn[i][j]];
                    ds.unionBySize(i,v);
                }
                else{
                    um[accn[i][j]]=i;
                }
            }
        }

        vector<string>v[n];

        for(auto it:um){
            int u = ds.findUltPar(it.second);

            v[u].push_back(it.first);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(v[i].empty()){
                continue;
            }

            sort(v[i].begin(),v[i].end());

            vector<string>temp;
            temp.push_back(accn[i][0]);

            for(auto it:v[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

        

        return {{}};
    }
};