class Solution {
    public int orangesRotting(int[][] grid) {
        /*
        - Check already rooten cells
        - traverse from rotten cell to other fresh celss
        - 
         */
        
        int rows = grid.length;
        int cols = grid[0].length;

        int[] drow = {-1,1,0,0};
        int[] dcol = {0,0,1,-1};
        int minTime = 0;

        Queue<int[]>q = new LinkedList<>();
        int[][] vis = new int[rows][cols];

        // Traverse 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){ // if cell is rotten
                    vis[i][j]=1;
                    q.offer(new int[]{0,i,j});
                }
            }
        }

        // traverse others brow
        while(!q.isEmpty()){
            int[] curr = q.poll();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];

            minTime = Math.max(minTime,t);

            for(int i=0;i<4;i++){
                int newX = drow[i]+r;
                int newY = dcol[i]+c;

                if(isSafe(newX,newY,rows,cols) && grid[newX][newY]==1 && vis[newX][newY]==0){
                    vis[newX][newY]=1;
                    q.offer(new int[]{t+1,newX,newY});
                }
            }
        }

        // last chekc 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }

        return minTime;
    }

    private boolean isSafe(int r,int c,int rows,int cols){
        return r>=0&&r<rows&&c>=0&&c<cols;
    }
}