class Solution {
public:
    bool isPowerOfFour(int n) {
       // I need to check it's power of 4 or not. 
       // Let see ki how can i check ? => Yes, bro 
       for(int i=0;i<32;i+=2){
        if(n==(1<<i)){
            return true;
        }
       }
       return false;
    }
};