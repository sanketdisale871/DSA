class Solution {
public:
    int largestCombination(vector<int>& cands) {
        int maxiNums = 0;
        int n = cands.size();

        for(int bit=0;bit<32;bit++){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(cands[i] & (1<<bit)){
                    cnt++;
                }
            }
            maxiNums = max(maxiNums,cnt);
        }
        return maxiNums;
    }
};