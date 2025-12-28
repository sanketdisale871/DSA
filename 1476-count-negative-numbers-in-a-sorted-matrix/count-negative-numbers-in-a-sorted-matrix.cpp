class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negCnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        int i=0,j=n-1;

        while(j>=0 && i<m){
            if(grid[i][j]<0){
                j--;
            }
            else{
                int currRowCnt = n-j-1;
                // cout<<"i : "<<i<<" currRowCnt: "<<currRowCnt<<endl;
                negCnt+=(currRowCnt);
                i++;
            }
        }

        if(i<m){
            int remRows= m-i;
            int currRowCnt = (n-j-1)*remRows;
            negCnt+=(currRowCnt);

        //  cout<<"i : "<<i<<" currRowCnt: "<<currRowCnt<<endl;
        }
        else if(grid[m-1][0]<0)
        {
            int currRowCnt = n-j-1;
            cout<<"i : "<<i<<" currRowCnt: "<<currRowCnt<<endl;
             negCnt+=(currRowCnt);
        }
        return negCnt;
    }
};