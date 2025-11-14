class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0));

        for(auto it:queries){
            int ur  = it[0];
            int uc = it[1];
            int lr = it[2];
            int lc = it[3];

            for(;ur<=lr;ur++){
                int cc = uc;
                for(;cc<=lc;cc++){
                    mat[ur][cc]+=1;
                }
            }
        }
        return mat;
    }
};