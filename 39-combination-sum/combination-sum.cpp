class Solution {
    private:
    vector<vector<int>>ans;
    void solve(int ind,vector<int>&ar,int tar,vector<int>&tmp){

        

        // base case 
        if(ind>=ar.size()){
            
            if(tar==0){
            ans.push_back(tmp);
            return ;
            }
            return;
        }

        // Pick 
        if(ar[ind]<=tar){
            tmp.push_back(ar[ind]);
            solve(ind,ar,tar-ar[ind],tmp);
            tmp.pop_back();
        }

        solve(ind+1,ar,tar,tmp);
        // Non-Pick
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>tmp;

        solve(0,candidates,target,tmp);


        return ans;
    }
};