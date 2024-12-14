class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
int n = nums.size();
    long long ans = 0;
    int i = 0, j = 0;
    deque<int> dq1;
    deque<int> dq2;

    for (int j =0;j<n;j++) {
       
        while (!dq2.empty() && nums[dq2.back()] > nums[j]) {
            dq2.pop_back();
        }
        while (!dq1.empty() && nums[dq1.back()] < nums[j]) {
            dq1.pop_back();
        }
        dq1.push_back(j);
        dq2.push_back(j);

        while(nums[dq1.front()]-nums[dq2.front()]>2){
            if(dq1.front() == i){
                dq1.pop_front();
            }
            if(dq2.front()== i){
                dq2.pop_front();
            }
            i++;
        }
        ans+=(j-i)+1;       
    }

    return ans;

    }
};