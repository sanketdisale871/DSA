class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans;

        int m = grid.size();
        // int n = grid[0].size();
        vector<vector<int>>prefMax(m,vector<int>(m));

        for(int i=0;i<=m-3;i++){
            vector<int>temp;

            for(int j=0;j<=m-3;j++){
                int maxi = INT_MIN;
                for(int t = i;t<=i+2;t++){
                    for(int k = j;k<=j+2;k++){
                        maxi = max(maxi,grid[t][k]);
                    }
                }
                temp.push_back(maxi);
            }
            ans.push_back(temp);
            
        }

     

        return ans;
    }
};