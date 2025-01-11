class Solution {
public:
    bool canConstruct(string s, int k) {
        // Need to add the K palindrome String
        if(s.length()<k){
            return false;
        }
        unordered_map<char,int>um;

        for(auto ch:s){
            um[ch]++;
        }

        int oddCnt = 0;

        for(auto it:um){
            if(it.second%2 !=0){
                oddCnt++;
            }
        }

        return oddCnt<=k;
    }
};