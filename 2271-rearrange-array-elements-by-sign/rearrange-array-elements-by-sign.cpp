class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        queue<int>qPos;
        queue<int>qNeg;

        for(auto it:nums){
            if(it<0){
                qNeg.push(it);
            }
            else{
                qPos.push(it);
            }
        }

        int itr = 0;

        while(!qPos.empty() && !qNeg.empty()){
            int firNum = qPos.front();qPos.pop();
            int secNum = qNeg.front();qNeg.pop();

            ans[itr++]=firNum;
            ans[itr++]=secNum;
        }





        return ans;
    }
};