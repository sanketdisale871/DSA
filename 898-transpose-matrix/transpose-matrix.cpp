class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>transpos;
          for(int i=0;i<matrix[0].size();i++){
            vector<int>temp;
        for(int j=0;j<matrix.size();j++){
            temp.push_back(matrix[j][i]);
        }
        transpos.push_back(temp);
    }
        return transpos;
    }
};