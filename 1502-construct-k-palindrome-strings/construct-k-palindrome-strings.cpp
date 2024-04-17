class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(k>n){
            return false;
        }

       
        unordered_map<char,int>um;

        for(auto it:s){
            um[it]++;
        }

        int oddCnt = 0;

        for(auto it:um){
            if(it.second & 1){
                oddCnt++;
            }
        }

        return oddCnt<=k;
    }
};