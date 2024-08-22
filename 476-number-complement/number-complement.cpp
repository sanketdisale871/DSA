class Solution {
public:
    int findComplement(int num) {
        int ans = 0;

        int bitNo = 0;

        while(num){
            int mask = num&(1<<0);
            // cout<<"mask : "<<mask<<endl;
            if(mask==0){
                ans = ans | (1<<bitNo);
            }

            bitNo++;
            num>>=1;
        }
        return ans;
    }
};