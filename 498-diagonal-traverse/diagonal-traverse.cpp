class Solution {
    /*
stCol : 0
it: 1
stCol : 1
it: 2
it: 4
stCol : 2
it: 3
it: 5
it: 7
stRow : 1
it: 6it: 8stRow : 2
it: 9
    */
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int rows = mat.size();
        int cols = mat[0].size();

        bool isSwap = true;

        // Traverse all cols 
        int stCol=0;
        for(;stCol<cols;stCol++){
            int r = 0;int c = stCol;

            vector<int>res;

            while(r<rows && c>=0){
                res.push_back(mat[r][c]);
                r++;
                c--;
            }

            if(isSwap){
                reverse(res.begin(),res.end());
            }
            isSwap=!isSwap;
            
            //  cout<<"stCol : "<<stCol<<endl;
            // Push result in answer 
            for(auto it:res){
                // cout<<"it: "<<it<<endl;
                ans.push_back(it);
            }
        }
        
        // Traverse all rows 
        int stRow = 1;

        for(;stRow<rows;stRow++){
            int r = stRow,c =cols-1;
            vector<int>res;
            while(r<rows && c>=0){
                res.push_back(mat[r][c]);
                r++;
                c--;
            }

            if(isSwap){
                reverse(res.begin(),res.end());
            }
            isSwap=!isSwap;

            // cout<<"stRow : "<<stRow<<endl;
            for(auto it:res){
                // cout<<"it: "<<it;
                ans.push_back(it);
            }
        }
        return ans;
    }
};