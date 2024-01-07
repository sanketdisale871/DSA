class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        int n = nums1.size();

        unordered_set<int>common;

        for(auto it:st1){
            if(st2.count(it)){
                common.insert(it);
            }
        }

        int n1 = st1.size(); // Only element from Set A, will conribute in Final
        int n2 = st2.size(); // Onely element from Set B, will contribute in Final
        int cmn = common.size();

        int res = min(n/2,n1-cmn)+min(n/2,n2-cmn)+cmn;

        return res>n?n:res;
    }
};