class Solution {
    /*
    1) One loop => Will check it is possible 
    2) Possible wala : 
     - Can i partition given string square => So their sum value equal to the n 
    */

    bool isPossiblePunishmentNum(int sum,string sqString){
        if(sqString == ""){
            if(sum==0){
                return true;
            }
            return false;
        }

        if(sum<0){
            return false;
        }

        for(int i=0;i<sqString.length();i++){
            string lef = sqString.substr(0,i+1);
            string righ = sqString.substr(i+1);

            int leftNum = stoi(lef);

            bool isPossible = isPossiblePunishmentNum(sum-leftNum,righ);

            if(isPossible){
                return true;
            }
        }

        return false;
    }


public:
    int punishmentNumber(int n) {
        int cntPunishmentNums = 1;


        for(int i=2;i<=n;i++){
            int sq = i*i;
            string sqString = to_string(sq);

            if(isPossiblePunishmentNum(i,sqString)){
                cntPunishmentNums+=(sq);
            }
        }


        return cntPunishmentNums;
    }
};