class Solution {
    private:
    typedef long long int ll;
    int findSubProdGreK(vector<int>&nums,int k){
        int ans = 0;
        int n = nums.size();
        int i=0,j=0;
        ll prod = 1;


        while(j<n){
            prod*=nums[j];

            if(prod<k){
                j++;
            }
            else{

                while(prod>=k && i<=j){
                    ans+=(n-j);
                    prod/=nums[i];
                    i++;
                }                
                j++;
            }
        }
        return ans;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //edge case 
        if(k==0){
            return 0;
        }

        ll n = nums.size();

        ll tot = n*(n+1)/2;

        return tot-findSubProdGreK(nums,k);
    }
};