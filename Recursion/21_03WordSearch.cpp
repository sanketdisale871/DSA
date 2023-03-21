class Solution {
public:
    //             [up,left,down,right]
    const int dr[4]={-1,0,1,0};
    const int dc[4]={0,-1,0,1};

    


    bool isSafe(int x,int y,vector<vector<char>>& board,int si,string word){
        if((x>=0 and x<board.size()) and (y>=0 and y<board[0].size()) and (board[x][y] != '.') 
        and (board[x][y]==word[si])){
            return true;
        }
        return false;
    }

    bool explore(int i,int j,vector<vector<char>>& board,int si,string word){
        // base case
        if(si==word.length()){
            return true;
        }

        for(int dir=0;dir<4;dir++){
            int x = i+dr[dir];
            int y = j + dc[dir];
            if(isSafe(x,y,board,si,word)){
                char ch = board[x][y];
                board[x][y]='.';

                bool aageSolution = explore(x,y,board,si+1,word);

                if(aageSolution){
                    return true;
                }
                else{
                    board[x][y]=ch;
                }
          }
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    char ch = board[i][j];
                    board[i][j]='.';
                    bool res = explore(i,j,board,1,word);
                    if(res){
                        return true;
                    }
                    else{
                        board[i][j]=ch;
                    }
                }
            }
        }
        return false;
    }
};
