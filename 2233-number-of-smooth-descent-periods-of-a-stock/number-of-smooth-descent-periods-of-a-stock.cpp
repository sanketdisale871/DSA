class Solution {
public:
typedef long long int ll;
    long long getDescentPeriods(vector<int>& prices) {
        ll siz = prices.size();

        ll totSmoothDecent = 1;
        ll contiCnt = 1;

        for(int i=1;i<siz;i++){
            if(prices[i]+1==prices[i-1]){
                contiCnt++;
            }
            else{
                contiCnt = 1;
            }
            totSmoothDecent+=contiCnt;
        }


        return totSmoothDecent;
    }
};