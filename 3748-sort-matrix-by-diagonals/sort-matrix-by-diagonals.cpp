class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        /*
    Bottom-Left => Decreasing Order
    TOP-RIGHT => Increasing Order        
        */
        

        int m = grid.size();
        int n = grid[0].size();vector<vector<int>>ans(m,vector<int>(n,0));


        // Col traversal 
        for(int col=1;col<n;col++){
            int r = 0;
            int c = col;
            vector<int>temp;

            while(r<m && c<n){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
             sort(temp.begin(),temp.end());
          

            r = 0;
            int i =0;
            c = col;

            while(r<m && c<n){
                ans[r][c]=temp[i];
                r++;
                c++;
                i++;
            }
        }
        // Row Traversal => Let's see ki kaise hoga?
        for(int row=0;row<n;row++){
            int r = row;
            int c = 0;
            vector<int>temp;

            while(r<m && c<n){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
           
              sort(temp.begin(),temp.end(),greater<>());

            r = row;
            int i =0;
            c = 0;

            while(r<m && c<n){
                ans[r][c]=temp[i];
                r++;
                c++;
                i++;
            }
        }



        return ans;
    }
};