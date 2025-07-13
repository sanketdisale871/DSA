class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& plyrs, vector<int>& trnrs) {
        sort(plyrs.begin(),plyrs.end());
        sort(trnrs.begin(),trnrs.end());
        int n = plyrs.size();

        int cnt = 0;

        int i=0,j=0;

        while(i<plyrs.size() && j<trnrs.size()){
            if(plyrs[i]<=trnrs[j]){
                cnt++;
                i++;j++;
            }
            else{
                j++;
            }
        }


        return cnt;
    }
};