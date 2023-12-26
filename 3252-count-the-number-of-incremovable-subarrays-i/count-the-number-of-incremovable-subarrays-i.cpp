class Solution {
public:
    typedef long long int ll;

    bool check(ll l,ll r,vector<int>&nums){

       ll n = nums.size();
       // Left wala array part
       for(ll i=0;i<l-1;i++){
           if(nums[i]>=nums[i+1]){
               return false;
           }
       }

        // Right wala part array
        for(ll i=r+1;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }

        if(l>0 && r<n-1 && nums[l-1]>=nums[r+1]){
            return false;
        }

        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size();

        ll ans = 0;

        for(ll i=0;i<n;i++){  
            for(ll j=i;j<n;j++){
                if(check(i,j,nums)){
                    cout<<"i :  "<<i<<" j : "<<j<<endl;
                    ans++;
                }
            } 
        }
        return (int)ans;
    }
};