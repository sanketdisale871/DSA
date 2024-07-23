class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        // vector<int>ans;
        unordered_map<int,int>frq;

        for(auto it:nums){
            frq[it]++;
        }

        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(frq[a]!=frq[b]){
                return frq[a]<frq[b];
            }
            else{
                return a>b;
            }
        });


        return nums;
    }
};