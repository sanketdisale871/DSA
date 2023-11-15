class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>minDq;
        deque<int>maxDq;

        int ans = 0;
        int i =0,j=0;
        int n = nums.size();

        while(j<n){

            // Max Dq
            while(!maxDq.empty() && maxDq.back()<nums[j]){
                maxDq.pop_back();
            }
            maxDq.push_back(nums[j]);

            // min dq
            while(!minDq.empty() && minDq.back()>nums[j]){
                minDq.pop_back();
            }
            minDq.push_back(nums[j]);


            if((maxDq.front() - minDq.front())<=limit){
                // cout<<' i : '<<i<<" j: "<<j<<" Len : "<<j-i+1<<endl;
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                while((maxDq.front() - minDq.front())>limit && i<=j){
                    if(maxDq.front()==nums[i]){
                        maxDq.pop_front();
                    }

                    if(minDq.front() == nums[i]){
                        minDq.pop_front();
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};