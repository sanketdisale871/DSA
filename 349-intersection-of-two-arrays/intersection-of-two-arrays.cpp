class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1;
        unordered_set<int>st2;

        for(auto it:nums1){
            st1.insert(it);
        }

        for(auto it:nums2){
            st2.insert(it);
        }

        vector<int>ans;

        for(auto it:st2){
            if(st1.count(it)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};