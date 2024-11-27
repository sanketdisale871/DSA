class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10){
            return false;
        }

        int cnt = 1;
        int stones = 10;

        while(n>0){
            n-=stones;

            if(cnt&1){
                if(n<0){
                    return false;
                }
            }
            else{
                if(n<0){
                    return true;
                }
            }
            cnt++;
            stones--;
        }

        if(cnt&1){
               return false;
            }
            else{
               return true;
            }

        
    }
};