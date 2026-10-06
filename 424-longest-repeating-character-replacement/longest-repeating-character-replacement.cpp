class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);

        int longLen = 0;
        int maxiOccur = 0;
        int i=0,j=0;

        while(j<s.length()){
            freq[s[j]-'A']++;
            maxiOccur = max(maxiOccur,freq[s[j]-'A']); 

            if((j-i+1)-maxiOccur<=k){
                longLen = max(longLen,j-i+1);
                j++;
            }
            else{
                while((j-i+1)-maxiOccur > k && i<=j){
                    freq[s[i]-'A']--;
                    i++;
                }
                j++;
            }
        }
        return longLen;
    }
};