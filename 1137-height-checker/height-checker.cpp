class Solution {
public:
    int heightChecker(vector<int>& hts) {
        vector<int>freqNums(101,0);

        for(auto it:hts){
            freqNums[it]++;
        }

        int currHt=0,itr=0;

        int misMatch=0;

        while(itr<hts.size() && currHt<101){
            if(freqNums[currHt]==0){
                currHt++;
            }
            else{
                if(currHt != hts[itr]){
                    misMatch++;
                }
                itr++;
                freqNums[currHt]--;
            }
        }  
        return misMatch; 
    }
};