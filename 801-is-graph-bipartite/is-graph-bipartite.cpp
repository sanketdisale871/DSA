class Solution {
    private:
    bool dfsTrav(int col,int node,vector<int>&graphCol,vector<vector<int>>& graph){
        graphCol[node]=col;

        for(auto it : graph[node]){
            if(graphCol[it]==-1){
                if(!dfsTrav(!col,it,graphCol,graph)){
                    return false;
                }
            }
            else if(graphCol[it]==col){
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>graphCol(n,-1);

        for(int i=0;i<n;i++){
                if(graphCol[i]==-1){
                    if(!dfsTrav(0,i,graphCol,graph)){
                        return false;
                    }
                }
        }

        return true;
    }
};