class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;

        unordered_map<int,int>um;

        for(auto num : nums){
            um[num]++;
        }

        while(um.size()>0){

            vector<int>res;

            for(auto& it : um){
                int num = it.first;
              
                cout<<um[num]<<endl;
                res.push_back(num);

                um[num]--;
            }

            for(auto it : res){
                if(um[it]==0){
                    um.erase(it);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};