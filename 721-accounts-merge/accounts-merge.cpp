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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accnt) {
        vector<vector<string>> ans;
        int n = accnt.size();

        unordered_map<string,int>um;

        DisjointSet ds(n);

        // Step1 : Indexing of Mails with their index 
        for(int i=0;i<n;i++){
            for(int j=1;j<accnt[i].size();j++){
                if(um.find(accnt[i][j])==um.end()){
                    um[accnt[i][j]]=i;
                }
                else{
                    ds.unionBySize(i,um[accnt[i][j]]);
                }
            }
        }

        // Step 2 : Merging the account of going same parent
        vector<string>merge[n];

        for(auto it:um){
            string mail = it.first;
            int node =  ds.findUltPar(it.second);

            merge[node].push_back(mail);
        }

        

        for(int i=0;i<n;i++){
            if(merge[i].size()==0){
                continue;
            }

            sort(merge[i].begin(),merge[i].end());

            vector<string>temp;

            temp.push_back(accnt[i][0]);

            for(auto it:merge[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};