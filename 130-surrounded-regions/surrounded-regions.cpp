class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();


        queue<pair<int,int>>q;
        // Collecting the Boundry 'O' s
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O'){
                      q.push({i,j});
                      board[i][j]=-1;
                    }
                }
            }
        }

        // BFS Traversal
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            
            int drow[] ={0,0,-1,1};
            int dcol[]={-1,1,0,0};

            for(int i=0;i<4;i++){
                int newX = drow[i]+x;
                int newY = dcol[i]+y;

                if((newX>=0 && newX<m) && (newY>=0 && newY<n)&&
                (board[newX][newY]=='O')){
                    q.push({newX,newY});
                    board[newX][newY]=-1;
                }
            }
        }

        /* Traversing the board doing the apna change*/

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};