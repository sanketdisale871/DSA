#include <bits/stdc++.h> 

bool isSafe(int x,int y,vector<vector<int>>&board,int row,int col){
    if((x>=0 && y>=0) && (x<row && y<col) && (board[x][y]==-1)){
        return true;
    }
    return false;
}

bool solve(vector<vector<int>>&board,int x,int y,int move,int row,int col){
    // Base cased
    // sabhi row and colns bhar gaye
    if(move==(row*col)-1){
        return true;
    }
    
    vector<vector<int>>possPath = {
        {2,1},{2,-1},{-2,1},{-2,-1},
        {1,2},{1,-2},{-1,2},{-1,-2}
    };
    
    for(int i=0;i<possPath.size();i++){
        int X = x + possPath[i][0];
        int Y = y + possPath[i][1];
        
        if(isSafe(X,Y,board,row,col)){
          
            board[X][Y]=move+1;
            
            bool aageSol = solve(board,X,Y,move+1,row,col);
            
            if(aageSol){
                return true;
            }else{
                // backtreaking
                board[X][Y]=-1;
            }
        }
    }
    return false;
}

vector<vector<int>> knightTour(int row, int col) {
    /* 
        Return matrix of size n*m where integer
        at cell(i, j) represent move number of knight to reach that
        cell. Move number start from 0.

        It may be possible that there is no possible order to visit each cell
        exactly once. In that case, return a matrix of size n*m having all the values
        equal to -1.
    */
    
    vector<vector<int>>board(row,vector<int>(col,-1));
    
    int x=0,y=0;
    board[x][y]=0;
    int move =0;
    
    if(solve(board,x,y,move,row,col)){
        return board;
    }else{
        board[0][0]=-1;
        return board;
    }
    
    
    
  
}
