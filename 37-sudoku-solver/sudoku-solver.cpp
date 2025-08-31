class Solution {
    
public:
    
    bool isSafe(vector<vector<char>>& board,int row,int col,char val){
        
        for(int i=0;i<9;i++){
            
            // row check
            if(board[row][i]==val){
                return false;
            }
            
            // col check
            if(board[i][col]==val){
                return false;
            }
            
            // grid checking 3*3
            
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val){
                return false;
            }
        }
        return true;
        
    }
    
    bool solve(vector<vector<char>>& board){
        
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                // we enetered in the board
                
                if(board[row][col]=='.'){
                    // jar board madhil cell empty asel
                    
                    for(int val='1';val<='9';val++){
                        if(isSafe(board,row,col,val)){
                            board[row][col]=val;
                            
                            bool aageSolution = solve(board);
                                                        
                            if(aageSolution){
                                return true;
                            }else{
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);        
    }
};