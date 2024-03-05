class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int ans = 0;

        // According ending position I have to Sortting
        sort(tasks.begin(),tasks.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });

        vector<bool>isUsed(2001,false);

        for(auto it:tasks){
            // Starting se traversal 
            for(int i=it[0];i<=it[1]&&it[2]>0;i++){
                if(isUsed[i]){
                    it[2]--;
                }
            }

            // Ending se mark kar raha 
            for(int i=it[1];i>=it[0] && it[2]>0;i--){
                if(!isUsed[i]){
                    isUsed[i]=true;
                    it[2]--;
                    ans++;
                }
            }
        }
        return ans;
    }
};