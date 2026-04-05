class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int> intiMove = {0,0};

        for(auto it:moves){
            if(it=='U'){
                intiMove.first-=1;
            }
            else if(it=='D'){
                intiMove.first+=1;
            }
            else if(it=='L'){
                intiMove.second-=1;
            }
            else{
                intiMove.second+=1;
            }
        }

        if(intiMove.first==0 && intiMove.second==0){
            return true;
        }
        return false;
    }
};