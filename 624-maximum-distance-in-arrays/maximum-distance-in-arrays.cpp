class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int t = arrays[0].size();

        int mini= arrays[0][0];
        int maxi = arrays[0][t-1];

        int ans = INT_MIN;

        for(int i=1;i<arrays.size();i++)
        {    auto it = arrays[i];
            int diff1 = abs(mini-it[it.size()-1]);
            int diff2 = abs(maxi - it[0]);

            ans = max({ans,diff1,diff2});

            mini = min(mini,it[0]);
            maxi = max(maxi,it[it.size()-1]);
        }

        return ans;
    }
};