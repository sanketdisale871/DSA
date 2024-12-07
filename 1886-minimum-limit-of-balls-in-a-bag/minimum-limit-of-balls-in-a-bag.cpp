class Solution {
    private:
    typedef long long int ll;

    bool isPossible(ll mid,vector<int>&nums,int maxOper){
        int currOper = 0;

        for(auto it:nums){
            if(it%mid!=0){
                currOper+=(it/mid);
            }
            else{
                currOper+=(it/mid)-1;
            }
        }
        return currOper<=maxOper;
    }
public:
    int minimumSize(vector<int>& nums, int maxOper) {
        ll low = 1;
        ll high = INT_MAX;
        ll ans = 0;

        while(low<=high){
            ll mid = low + (high-low)/2;

            if(isPossible(mid,nums,maxOper)){
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