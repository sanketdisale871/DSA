class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        map<int, int> um;
        um[-1] = 0;
        int maxi = 0;

        sort(items.begin(), items.end());

        for (auto it : items) {
            int pr = it[0];
            maxi = max(maxi, it[1]);
            um[pr] = maxi;
        }

        for (auto it : queries) {
            auto itt = um.upper_bound(it);
            itt--; // Move iterator back to the largest element <= it
            ans.push_back(itt->second);
        }

        return ans;
    }
};
