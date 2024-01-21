class Solution {
    
public:
    int minimumCost(vector<int>& nums) {
        
        int totCost = nums[0];

        int firSmall=INT_MAX;
        int secSmall=INT_MAX;
            
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]<firSmall){
                secSmall=firSmall;
                firSmall=nums[i];
            }
            else if(nums[i]<secSmall){
                secSmall=nums[i];
            }
        }
        
        return totCost+firSmall+secSmall;
    }
};