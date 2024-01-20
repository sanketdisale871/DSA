class Solution {
public:
    typedef long long int ll;
    int minimumArrayLength(vector<int>& nums) {
        int minElem = *min_element(nums.begin(),nums.end());

        for(auto num:nums){
            if(num%minElem > 0){
                return 1;
            }
        }

        int cnt = count(nums.begin(),nums.end(),minElem);

        return (cnt+1)/ 2;
    }
};