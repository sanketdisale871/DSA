class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        for(int a : nums) mp[a]++;
        int i = 0, res = 0;
        for(auto it : mp)
            res += it.second * i++;
        return res;
    }
};