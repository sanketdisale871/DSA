class Solution {
    private:
    typedef long long int ll;
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       ll cnt = 0;

       unordered_map<ll,ll>um;

    //    sort(nums3.begin(),nums3.end());

       for(auto num4 : nums4){
           for(auto num3:nums3){
               um[num3+num4]++;
           }
       }     

       for(ll i=0;i<nums1.size();i++){
           for(ll j=0;j<nums2.size();j++){
             ll temp = nums1[i]*1ll+nums2[j]*1ll;
             cnt+=um[-temp];          
           }
       }
       return (int)cnt;
 
    }
};