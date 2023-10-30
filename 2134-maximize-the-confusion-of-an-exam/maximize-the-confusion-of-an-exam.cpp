class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int>um;

        int maxiOccur = 0;
        int i=0,j=0;
        int n = answerKey.length();
        int maxiLen = 0;

        while(j<n){
            um[answerKey[j]]++;

            maxiOccur = max(maxiOccur,um[answerKey[j]]);

            if((j-i+1)-maxiOccur <=k){
                maxiLen = max(maxiLen,j-i+1);
                j++;
            }
            else{
                while(((j-i+1)-maxiOccur >k) && i<=j){
                    um[answerKey[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxiLen;
    }
};