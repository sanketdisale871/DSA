class Solution {

    private boolean isSafe(int newR,int newC,int[][] grid){
        return newR>=0 && newR<grid.length && newC>=0 && newC<grid[0].length;
    }

    private long dfs(int r,int c,int[][] grid,int[][] vis){
        long sum =grid[r][c];
        vis[r][c]=1;


        int[] drow = {-1,1,0,0};
        int[] dcol = {0,0,1,-1};


        for(int i=0;i<4;i++){
            int newR = drow[i]+r;
            int newC = dcol[i]+c;

            if(isSafe(newR,newC,grid) && vis[newR][newC]==0 && grid[newR][newC]!=0){
                sum+=dfs(newR,newC,grid,vis);
            }
        }

        return sum;

    }

    public int countIslands(int[][] grid, int k) {
        // if Value !=0 then traverse that row, column with 4 directionally
        // Sum it all & Check it
        // 
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] vis = new int[rows][cols];
        int islands = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    // int totVal = 0;
                     long totVal = dfs(i,j,grid,vis);

                    if(totVal%k==0){
                        islands++;
                    }
                }
            }
        }



        return islands;
    }
}