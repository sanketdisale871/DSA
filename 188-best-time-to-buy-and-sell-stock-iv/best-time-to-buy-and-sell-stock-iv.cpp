class Solution {
    private:
    vector<vector<vector<int>>>dp;
    int findMaiProf(int ind,int k,int isBuy,vector<int>&price){
        // base case 
        if(ind>=price.size() || k==0){
            return 0;
        }

        if(dp[ind][k][isBuy]!=-1){
            return dp[ind][k][isBuy];
        }

        if(isBuy){
            int op1 = -price[ind]+findMaiProf(ind+1,k,0,price);
            int op2 = findMaiProf(ind+1,k,1,price);
            return dp[ind][k][isBuy]=max(op1,op2);
        }
        else{
            int op1 = price[ind]+findMaiProf(ind+1,k-1,1,price);
            int op2 = findMaiProf(ind+1,k,0,price);
            return dp[ind][k][isBuy]=max(op1,op2);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp.resize(vector<vector<int>>(n,vector<int>(k)),ve)
        dp.assign(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return findMaiProf(0,k,1,prices);
    }
};