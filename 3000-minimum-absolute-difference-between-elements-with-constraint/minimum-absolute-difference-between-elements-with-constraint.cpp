class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;

        multiset<int>st; // Why Multiset : Want to perform lower bound (Applicable on Sorted Array)

        for(int i=x;i<nums.size();i++){
            st.insert(nums[i-x]);

            auto it = st.lower_bound(nums[i]);

            if(it != st.end()){
                ans = min(ans,abs(*it - nums[i]));
            }

            if(it != st.begin()){
                it--;
                ans = min(ans,abs(*it - nums[i]));
            }
        }
        return ans;
    }
};