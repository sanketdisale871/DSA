class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;

        // pair<ans,ind>
        queue<pair<int,int>>minHeap;

        minHeap.push({0,nums[0]});

        int possSub = (1<<nums.size());

        while(!minHeap.empty() && possSub--){
            auto it = minHeap.front();minHeap.pop();

            int r = it.second;
            int ind = it.first;

            sum+=r;

            if(ind<nums.size()-1){
                minHeap.push({ind+1,r^nums[ind+1]});
            }

            if(ind<nums.size()-1){
                minHeap.push({ind+1,r^nums[ind]^nums[ind+1]});
            }
        }

        return sum;
    }
};