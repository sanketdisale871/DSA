class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    
        int cnt = 0;
        int n = nums.size();

        int lst = INT_MIN;

        for(int i=0;i<n;i++){
            int min = nums[i]-k;
            int max = nums[i]+k;

            if(lst<min){
                lst = min;
                cnt++;
            }
            else if(lst<max){
                lst = lst+1;
                cnt++;
            }
        }

        return cnt;
    }
};