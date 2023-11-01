class Solution {

public:
    #define ll long long 
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
      
        
        ll int sum1 = 0;
        ll int sum2=0;

        int z1 = 0;
        int z2 = 0;

        for(auto it :nums1){
            sum1+=it;
            z1+=(it==0);
        }

        for(auto it :nums2){
            sum2+=it;
            z2+=(it==0);
        }
        
        if(z1==0 && sum1 < sum2+z2){
            return -1;
        }
        
        if(z2==0 && sum2 < sum1+z1){
            return -1;
        }
        
       return max(sum1+z1,sum2+z2);
        
    }
};