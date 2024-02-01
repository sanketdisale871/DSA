class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        int n = nums.size();

        if(n%3 == 0){
            vector<int>temp;

            for(int i=0;i<n;i++){
                temp.push_back(nums[i]);
                
                if(temp.size()==3){
                    if(temp[2]-temp[0]<=k){
                        ans.push_back(temp);
                        temp.clear();
                    }
                    else{
                        return {};
                    }
                }
            }
        }
        else{
            return ans;
        }

        return ans;
    }
};