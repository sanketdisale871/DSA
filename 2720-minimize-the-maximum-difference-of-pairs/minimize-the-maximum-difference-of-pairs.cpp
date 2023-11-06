class Solution {
    private:

    bool isPossible(int mid,vector<int>&nums,int p){
        int i=1;
        int pari = 0;
        while(i<nums.size()){
            int diff = nums[i]-nums[i-1];

            if(diff<=mid){
                pari++;

                if(pari==p){
                    return true;
                }
                i+=2;
            }
            else{
                i++;
            }
        }
        return pari>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(n==1 || p==0){
            return 0;
        }

        sort(nums.begin(),nums.end());

        int low = 0;
        int high = nums[n-1]-nums[0];
        int ans = 0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,nums,p)){
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