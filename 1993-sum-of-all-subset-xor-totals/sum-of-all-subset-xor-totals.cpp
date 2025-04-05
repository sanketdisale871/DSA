class Solution {
    private:
    long long int totXorSum = 0;
 
    void calculateSubsetsXOR(int currXor,vector<int>&nums,int ind){
        // Base case
        if(ind>=nums.size()){
            totXorSum+=currXor;
            return ;
        }

    

        calculateSubsetsXOR(currXor^nums[ind],nums,ind+1);
        calculateSubsetsXOR(currXor,nums,ind+1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        int currXor = 0;

        calculateSubsetsXOR(currXor,nums,0);

        return totXorSum;
    }
};