class Solution {
public:
    int numRescueBoats(vector<int>& ppl, int limit) {
        sort(ppl.begin(),ppl.end());
        int n = ppl.size();
        int i=0,j=n-1;
        int rqBot = 0;

        while(i<j){
            if(ppl[j]>=limit){
                rqBot++;
                j--;
            }
            else{
                if(ppl[i]+ppl[j]<=limit){
                    rqBot++;
                    i++;j--;
                }
                else{
                    rqBot++;
                    j--;
                }
            }
        }

        if(i==j){
            rqBot++;
        }
        return rqBot;
    }
};