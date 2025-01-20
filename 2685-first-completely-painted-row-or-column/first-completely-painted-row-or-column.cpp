class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>um;

        for(int i=0;i<arr.size();i++){
            um[arr[i]]=i;
        }

        int smInd = INT_MAX;

        for(int i=0;i<mat.size();i++){
            int maxRat = 0;
            for(int j=0;j<mat[0].size();j++){
                maxRat = max(maxRat,um[mat[i][j]]);
            }
            smInd = min(smInd,maxRat);
        }

        for(int j=0;j<mat[0].size();j++){
            int maxRat = 0;
            for(int i=0;i<mat.size();i++){
                maxRat = max(maxRat,um[mat[i][j]]);
            }
            smInd = min(smInd,maxRat);
        }
        return smInd;
    }
};