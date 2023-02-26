class Solution {
public:
/*
    Algorithm : 
    rightSum = 0, leftSum = 0;

    i) First Calculate the right sum
    ii) Then during traversing array, rightSum = rightSum-currElem
        diff = abs(rightSum - leftSum)
        leftSum +=currElem ;
*/
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int>ans;
        
        int n = nums.size();
        
        int rsum = 0,lsum =0;
        
        for(int i=0;i<n;i++){
            rsum+=nums[i];
        }
        
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            
            ans.push_back(abs(rsum-lsum));
            
            lsum+=nums[i];
        }
        return ans;
    }
};
