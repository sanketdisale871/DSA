class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxiVal = 0;

        for(auto it:edges){
            maxiVal = max(maxiVal,it[1]);
            maxiVal = max(maxiVal,it[0]);
        }

        vector<int>edgesNode(maxiVal+1,0);

        for(auto it:edges){
            // cout<<it[0]<<" "<<it[1]<<endl;
            edgesNode[it[0]]++;
            edgesNode[it[1]]++;

            // cout<<edgesNode[it[0]]<<" "<<edgesNode[it[1]]<<endl;
        }

        for(int i=1;i<=maxiVal;i++){
            if(edgesNode[i]>=maxiVal-1){
                return i;
            }
        }
        return -1;
    }
};