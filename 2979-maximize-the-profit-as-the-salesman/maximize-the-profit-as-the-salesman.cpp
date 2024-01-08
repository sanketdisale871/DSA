class Solution {
    /* Approach : 
    1) Using dynamic programming with memoization to maximize the earnings from selling houses to buyers. 
    2) You sort the purchase offers based on starting indices. Then, through a recursive approach, you consider the options of either taking the current offer and recursively exploring further with the next valid offer index, or skipping the current offer and moving to the next one. 
    3) The memoization table stores already computed results to avoid redundant calculations, ultimately yielding the maximum amount of gold that can be earned.
    */
    private:
    vector<int>dp;

    // Function to find the next valid offer index for a given range
    int findNextIndex(vector<vector<int>>& offers,int x,int index){
        int low = index;
        int high = offers.size()-1;
        int ans = offers.size();

        while(low<=high){
            int mid = low + (high-low)/2;

            if(offers[mid][0]>x){ // Starting index (Offer House) must be grater than ending index of ( i.e. x)
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    int solve(int index,vector<vector<int>>& offers){
        // Base case
        if(index >= offers.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        // Find the index of the next valid offer that can be taken
        int nexIndex = findNextIndex(offers,offers[index][1],index); /* I am finding the next offers (if current offer i can take)*/
        
         // Calculate the maximum gold earned with and without taking the current offer
        int withTaking = offers[index][2] + solve(nexIndex,offers);
        int withOutTaking = solve(index+1,offers);

        // Store the maximum result in the dp table and return it
        return dp[index] = max(withTaking,withOutTaking);
    }

public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        dp.assign(offers.size()+1,-1);

        sort(offers.begin(),offers.end());

        return solve(0,offers);
    }
};