class Solution {
    private:
    int findNoOfPairs(int diff,vector<int>&nums){
        int currprs = 0;

        int i=0,j=0;

        while(j<nums.size()){
            int currDiff = nums[j]-nums[i];

            if(currDiff<=diff){
                currprs+=(j-i);
                j++;
            }
            else{
                while(i<j && nums[j]-nums[i]>diff){
                    i++;
                }
                currprs+=(j-i);
                j++;
            }
        }
        return currprs;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int low = INT_MAX,high;

        high = nums[n-1]-nums[0];

        for(int i=1;i<n;i++){
            low = min(low,nums[i]-nums[i-1]);
        }


        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            int prs = findNoOfPairs(mid,nums);

            if(prs>=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;

    }
};