class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>um;

        int n = s.length();
        int maxiOccur = 0;
        int maxiLen = 0;

        int i=0,j=0;

        while(j<n){
            um[s[j]]++;

            maxiOccur = max(maxiOccur,um[s[j]]);

            if((j-i+1)-maxiOccur <=k){
                maxiLen = max(maxiLen,j-i+1);
                j++;
            }
            else{
                while((j-i+1)-maxiOccur>k && i<=j){
                    um[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxiLen;
    }
};