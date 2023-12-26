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

        if(l>0 && r<n-1 && nums[l-1]>=nums[r+1]){ // Middle wali condition
            return false; 
        }

        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size();

        ll ans = 0;

        // Precomputation
        vector<ll>prefix(n,0);
        vector<ll>suffix(n,0);
        prefix[0]=1;
        suffix[n-1]=1;

        for(ll i=1;i<n;i++){
            if(nums[i]>nums[i-1] && prefix[i-1]==1){
                prefix[i]=1;
            }            
        }

        for(ll i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1] && suffix[i+1]==1){
                suffix[i]=1;
            }
        }



        for(ll i=0;i<n;i++){  
            for(ll j=i;j<n;j++){

                bool left = i==0 || prefix[i-1]==1 ? true:false;
                bool right = j==n-1 || suffix[j+1]==1  ?true:false;
                bool middle = true;

                if(i>0 && j<n-1 && nums[i-1]>=nums[j+1]){ // Middle wali condition
                    middle= false; 
                }

                if(left && right && middle){ // [0,....,i-1] [j+1,...n-1]
                    cout<<"i :  "<<i<<" j : "<<j<<endl;
                    ans++;
                }
            } 
        }
        return (int)ans;
    }
};