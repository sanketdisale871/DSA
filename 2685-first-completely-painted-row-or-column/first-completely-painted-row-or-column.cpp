class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // I will calculate the how many each row and column will get
        // maximum time to paint the row/col and taking minimum from them

        int m = mat.size();
        int n = mat[0].size();

        int ans = INT_MAX;

        // Hash the arr with index
        unordered_map<int,int>um;
        for(int i=0;i<arr.size();i++){
            um[arr[i]]=i;
        }

        // traverse the matrix for row How many taking time, taking minimum from them
        for(int i=0;i<m;i++){
            int rowMax = 0;
            for(int j=0;j<n;j++){
                rowMax = max(rowMax,um[mat[i][j]]);
            }
            ans = min(ans,rowMax);
        }

        // Traverse the matrix for column, How many taking time,taking minimum from them

        for(int j=0;j<n;j++){
            int colMax = 0;
            for(int i=0;i<m;i++){
                colMax = max(colMax,um[mat[i][j]]);
            }
            ans = min(ans,colMax);
        }

        return ans;       
    }
};