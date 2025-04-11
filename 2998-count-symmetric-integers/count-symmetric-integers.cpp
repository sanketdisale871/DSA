class Solution {
    private:
    bool isSymmetric(string temp){
        if(temp.length()%2!=0){
            return false;
        }
        int i=0,j=temp.length()-1;
        int frntSum=0,backSum=0;

        while(i<j){
            frntSum+=temp[i++]-'0';
            backSum+=temp[j--]-'0';
        }

        return frntSum==backSum;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        // Symmetric Integers were given.

        int cnt = 0;

        for(int itr=low;itr<=high;itr++){
            if(isSymmetric(to_string(itr))){
                cnt++;
            }
        }

        return cnt;

    }
};