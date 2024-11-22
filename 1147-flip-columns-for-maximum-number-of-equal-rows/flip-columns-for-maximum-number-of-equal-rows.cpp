class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<string,int>um;

        int ans = 0;

        for(int i=0;i<m;i++){
            int fst = mat[i][0];
            string str = "";

            for(int j=0;j<n;j++){
                if(mat[i][j]==fst){
                    str.push_back('1');
                }
                else{
                    str.push_back('0');
                }
            }
            um[str]++;
            ans = max(ans,um[str]);
        }
        return ans;
    }
};