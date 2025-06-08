class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        deque<int>dq;

        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }

            if(!dq.empty() && dq.front()<=i-k+1){
                dq.pop_front();
            }
        }

        return ans;        
    }
};