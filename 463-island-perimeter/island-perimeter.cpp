class Solution {
    private:
    int findArea(int x,int y,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        q.push({x,y});

        int are = 0;

        while(!q.empty()){
            auto it = q.front();q.pop();

            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,1,-1};

            cout<<" x : "<<it.first<<" y : "<<it.second<<" :: ";

            for(int i=0;i<4;i++){
                int newX = drow[i]+it.first;
                int newY = dcol[i]+it.second;

                if(newX<0 || newX>=grid.size() || newY<0 || newY>=grid[0].size() || grid[newX][newY]==0){
                    are++;
                    cout<<"newX "<<newX<<" newY "<<newY<<endl;
                }
                else if(grid[newX][newY]==1){
                    q.push({newX,newY});
                    grid[newX][newY]=-1;
                }
            }
        }

        return are;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=-1;
                    int res = findArea(i,j,grid);
                    return res;
                }
            }
        }
        return 0;
    }
};