class Solution {
    
public:
    vector<vector<string>>ans;
    
    bool isSafe(vector<string>&board,int row,int col,int n){
        
        int x = row;
        int y = col;
        
        // row checking
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }
        
        // upper digonal checking
        x= row;
        y=col;
        
        while((x>=0) &&(y>=0)){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
            x--;
        }
        
        // lower diagonal checking
        x=row;
        y=col;
        while((x<n)&&(y>=0)){
              if(board[x][y]=='Q'){
                return false;
            }
            y--;
            x++;
        }
        return true;
    }
    
    void solve(vector<string>&board,int n,int col){
        
        // base case -> aapan jar sarv columns check kele tar
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                
                solve(board,n,col+1);
                
                // backtrack
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board(n,string(n,'.'));
        
        solve(board,n,0);
        
        return ans;
    }
};
