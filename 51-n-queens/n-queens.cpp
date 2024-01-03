class Solution {
    private:
    vector<vector<string>> ans;

    bool isPossible(int row,int col,vector<string>&board){
        // Checking Upper Row 
        int x = row,y=col;

        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }

        // Checking row 
        x  = row;y=col;

        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }

        // Checking lower diagonal 
        x = row;y=col;

        while(x<board.size() && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void solve(int col,int n,vector<string>&board){
        // Base case 
        if(col>=n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++){
            if(isPossible(row,col,board)){
                board[row][col]='Q';

                solve(col+1,n,board);

                board[row][col]='.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        solve(0,n,board);

        return ans;
    }
};