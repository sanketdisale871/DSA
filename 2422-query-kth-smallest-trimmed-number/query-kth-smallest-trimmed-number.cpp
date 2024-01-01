class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto it:queries){
            int k = it[0];
            int tr = it[1];

            // pair<int,int> <num,ind>
            priority_queue<pair<string,int>>maxHeap;
            int n = nums[0].length();
            for(int i=0;i<nums.size();i++){
                
                string res = nums[i].substr(n-tr);

                maxHeap.push({res,i});

                if(maxHeap.size()>k){
                    maxHeap.pop();
                }
            }

            ans.push_back(maxHeap.top().second);
        }
        return ans;
    }
};