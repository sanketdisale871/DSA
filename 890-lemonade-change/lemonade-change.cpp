class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0;
        int t = 0;
        int tw = 0;

        for(auto it:bills){
            if(it==5){
                f++;
            }
            else if(it==10){
                if(f>0){
                    t++;
                    f--;
                }
                else{
                    return false;
                }
            }
            else{
                if(f>0 && t>0){
                    f--;
                    t--;
                    tw++;
                }
                else if(f>2){
                    f-=3;
                    tw++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};