class Solution {
    private Boolean[][][] dp;
    private boolean solve(int i,int j,char[][] grid ,int balance){
        if(i>=grid.length || i<0 || j>=grid[0].length || j<0){
            return false;
        }

        if(grid[i][j]=='('){
            balance++;
        }
        else{
            balance--;
        }

        if(balance<0){
            return false;
        }

        if(i==grid.length-1 && j==grid[0].length-1){
            if(balance==0){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[i][j][balance]!=null){
            return dp[i][j][balance];
        }

        boolean down = solve(i+1,j,grid,balance);
        boolean right = solve(i,j+1,grid,balance);

        return dp[i][j][balance]= (down || right);
    }
    public boolean hasValidPath(char[][] grid) {
        int balance = 0;
        int m = grid.length;
        int n = grid[0].length;

        if((m+n-1)%2!=0){
            return false;
        }

        dp = new Boolean[m][n][m+n];

        return solve(0,0,grid,balance);
    }
}