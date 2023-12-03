class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>st;

        for(auto num : nums){
            st.insert(num);
        }

        int conCnt = 0;

        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int currElem = nums[i];
                int currCnt = 1;

                while(st.find(currElem+1)!=st.end()){
                    currCnt++;
                    currElem = currElem+1;
                }

                conCnt = max(conCnt,currCnt);
            }
        }

        return conCnt;
    }
};