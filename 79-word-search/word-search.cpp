class Solution {
private:

    void dfsTrav(int i,int j,vector<vector<char>>& board,int ind,string &word,vector<vector<int>>&vis,bool &res){
        vis[i][j]=1;

        if(ind>=word.size()){
            res = true;
            return;
        }

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,1,-1};

        for(int ii=0;ii<4;ii++){
            int newX = drow[ii]+i;
            int newY = dcol[ii]+j;

            if((newX>=0 && newX<board.size()) && (newY>=0 && newY<board[0].size()) && board[newX][newY]==word[ind] && !vis[newX][newY]){
                dfsTrav(newX,newY,board,ind+1,word,vis,res);
            }
        }
        vis[i][j]=0;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>vis(m,vector<int>(n,0));
                    bool res = false;
                    dfsTrav(i,j,board,1,word,vis,res);

                    if(res){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};