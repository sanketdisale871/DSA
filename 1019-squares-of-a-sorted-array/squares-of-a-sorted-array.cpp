class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        // Placing the tow pointers at correct position -> just after the positive and negative
        int i,j;

        for(i=0;i<n;i++){
            if(nums[i]>=0){
                break;
            }
        }
        j = i-1;

        while((i<n) && (j>=0)){
            if(nums[i]==abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                ans.push_back(nums[i]*nums[i]);
                i++;
                j--;
            }
            else if(nums[i]<abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }

        while(i<n){
            ans.push_back(nums[i]*nums[i]);
            i++;
        }
        while(j>=0){
            ans.push_back(nums[j]*nums[j]);
            j--;
        }


        return ans;
    }
};