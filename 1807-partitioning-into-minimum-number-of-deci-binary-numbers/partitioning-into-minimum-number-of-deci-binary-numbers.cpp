class Solution {
public:
    int minPartitions(string n) {
        int maxDig = 0;

        for(auto it:n){
            maxDig = max(maxDig,it-'0');
        }
        return maxDig;
    }
};