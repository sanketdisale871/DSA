class Solution {
    private:
    vector<vector<int>>  ans;

    void solve(int ind,vector<int>& candidates, int target,vector<int>&temp){

        // Base case
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        if(ind==candidates.size()){
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            if(i>ind &&candidates[i-1]==candidates[i]){
                continue;
            }

            if(candidates[i]>target){
                break;
            }

            temp.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],temp);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,temp);

        return ans;
    }
};