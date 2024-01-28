class Solution {
public:
    int minBitFlips(int s, int g) {
        int cnt = 0;
        for(int bit = 0;bit<32;bit++){
            if((g&(1<<bit))!=0){ // Set Goal Bit
                if((s&(1<<bit))==0){ 
                    cnt++;
                }
            }
            else{
                if((s&(1<<bit))!=0){ // Not set Goal Bit 
                    cnt++;
                }
            }
        }
        return cnt;
    }
};