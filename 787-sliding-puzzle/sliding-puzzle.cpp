class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>dirs = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {3,1,5},
            {2,4}
        };

        queue<string>q;
        int steps = 0;

        string tar = "123450";
        
        string str = "";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                str.push_back(board[i][j]+'0');
            }
        }

        unordered_set<string>st;
        st.insert(str);

        q.push(str);

        while(!q.empty()){
            int siz = q.size();

            while(siz--){
                auto it = q.front();q.pop();

                if(it==tar){
                    return steps;
                }

                int curPos = it.find('0');

                for(auto mv:dirs[curPos]){
                    string nex = it;
                    swap(nex[curPos],nex[mv]);

                    if(st.count(nex)==0){
                        st.insert(nex);
                        q.push(nex);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};