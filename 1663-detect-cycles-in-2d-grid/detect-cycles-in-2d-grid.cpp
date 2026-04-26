class Solution {
    private:
    bool isSafe(int r,int c,int rows,int cols){
        return r>=0 && c>=0 && r<rows && c<cols;
    }
public:
bool containsCycle(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    int drow[] = {-1,1,0,0};
    int dcol[] = {0,0,1,-1};

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            if(vis[i][j]) continue;

            queue<pair<pair<int,int>, pair<int,int>>> q;
            q.push({{i,j},{-1,-1}});
            vis[i][j] = 1;

            while(!q.empty()){
                auto it = q.front(); q.pop();

                int r = it.first.first;
                int c = it.first.second;
                int pr = it.second.first;
                int pc = it.second.second;

                for(int k=0;k<4;k++){
                    int nr = r + drow[k];
                    int nc = c + dcol[k];

                    if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]==grid[r][c]){
                        if(!vis[nr][nc]){
                            vis[nr][nc] = 1;
                            q.push({{nr,nc},{r,c}});
                        }
                        else if(nr!=pr || nc!=pc){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
};