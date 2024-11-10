class Solution {
    typedef long long int ll;
    
    vector<vector<ll>>setBits;
    
    void preCal(vector<int>&nums){
        ll n = nums.size();
        
        setBits.resize(n+1,vector<ll>(32,0));
        
        for(ll i=0;i<n;i++){
            for(ll bit=0;bit<32;bit++){
                
                if(nums[i]&(1<<bit)){
                    setBits[i+1][bit]=1+setBits[i][bit];
                }
                else{
                    setBits[i+1][bit]=setBits[i][bit];
                }
            }
        }        
    }
    
    bool isPossible(vector<int>&nums,ll n,ll len,ll k){
        // ll left = 1;
        ll right = len;
        
        for(ll i=right;i<=n;i++){
            
            ll res = 0;
            
            for(ll bit=0;bit<32;bit++){
                ll setBitss = setBits[i][bit]-setBits[i-len][bit];
                
                if(setBitss>0){
                    res = (res|(1<<bit));
                }                
            }
            
            if(res>=k){
                return true;
            }
        }        
        return false;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ll ans = -1;
        
        preCal(nums);
        
        ll n = nums.size();
        ll low = 1;
        ll high = n;
        
        while(low<=high){
            ll mid = low + (high-low)/2;
            
            if(isPossible(nums,n,mid,k)){
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