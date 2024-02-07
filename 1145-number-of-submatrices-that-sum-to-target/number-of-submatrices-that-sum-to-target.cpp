class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        vector<vector<int>>pref(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    pref[i][j]=mat[i][j];
                }
                else{
                    pref[i][j]=mat[i][j]+pref[i][j-1];
                }
            }
        }


        for(int stCol=0;stCol<n;stCol++){
            for(int endCol=stCol;endCol<n;endCol++){
                int sum = 0;
                unordered_map<int,int>um;
                um[0]=1;

                for(int r=0;r<m;r++){
                    sum+=pref[r][endCol]-(stCol?pref[r][stCol-1]:0);

                    ans+=um[sum-target];

                    um[sum]++;
                }
            }
        }
        return ans;
    }
};