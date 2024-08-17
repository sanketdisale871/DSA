class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0]+0;

        int ans = 0;

        for(int i=1;i<values.size();i++){
            int res = values[i]-i + maxi;
            ans = max(ans,res);
            maxi = max(maxi,values[i]+i);
        }

        return ans;
    }
};