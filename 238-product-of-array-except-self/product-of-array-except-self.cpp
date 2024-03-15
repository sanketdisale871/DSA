class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int arrayNums = nums.size();
        
        vector<int>ans(arrayNums);

        vector<int>prefix(arrayNums); // prefix[ind] => Product of numbers from [0....ind]
        vector<int>suffix(arrayNums); // suffix[ind] => Product of numbers from [ind....arrayNums-1]

        int pr = 1;

        for(int i=0;i<arrayNums;i++){
            pr=(pr*nums[i]);

            prefix[i]=pr;
        }
        int suf = 1;
        for(int i=arrayNums-1;i>=0;i--){
            suf*=nums[i];

            suffix[i]=suf;
        }

        for(int i=0;i<arrayNums;i++){
            int left = 1;
            int right = 1;

            if(i>0){
                left = prefix[i-1];
            }

            if(i<arrayNums-1){
                right = suffix[i+1];
            }

            ans[i]=left*right;
        }

        return ans;
    }
};