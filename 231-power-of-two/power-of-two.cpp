class Solution {
    
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }

        long num = n;

        // if(n<0){
        //   num = labs(n);
        // }

        if((num & (num-1))){
            return false;
        }
        else{
            return true;
        }
    }
};