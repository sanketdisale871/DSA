class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(auto it:nums1){
            if(n2%2!=0){
                ans=(ans^it);
            }
        }

        for(auto it:nums2){
            if(n1%2!=0){
                ans=(ans^it);
            }
        }
        return ans;
    }
};