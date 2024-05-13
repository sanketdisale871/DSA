class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[i][0]==0){

                for(int j=0;j<n;j++){ // Flip if most significant bit have zero that place
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                }

            }
        }

        // Columns making more contributing

        for(int j=0;j<n;j++){
            int one = 0;

            for(int i=0;i<m;i++){
                if(grid[i][j]==1){
                    one++;
                }
            }

            int zr = m - one;

            if(zr>one){
                for(int i=0;i<m;i++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                }
                else{
                     grid[i][j]=0;
                }
            }
            }
        }

        int totScore = 0;

        for(int i=0;i<m;i++){
            int bit = 0;
            int res = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    res = res|(1<<bit);
                }
                bit++;
            }
            totScore+=res;
        }
        
        return totScore;
    }
};