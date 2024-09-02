class Solution {
public:
    typedef long long int ll;
    int chalkReplacer(vector<int>& chalk, int k) {

        ll totSum = 0;

        for (int studentChalkUse : chalk) {
            totSum += studentChalkUse;
        }


        ll rem = k%totSum;

        for(int i=0;i<chalk.size();i++){
            if(rem<chalk[i]){
                return i;
            }
            else{
                rem-=chalk[i];
            }
        }
        return 0;
    }
};