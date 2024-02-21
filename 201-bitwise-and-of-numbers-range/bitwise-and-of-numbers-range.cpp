class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;

        for(int bit=31;bit>=0;bit--){

            int lSet = left&(1<<bit);
            int rSet = right&(1<<bit);

            if(lSet && rSet){
                ans=(ans|(1<<bit));
            }
            else if(lSet || rSet){
                break;
            }
        }
        return ans;

    }
};