class Solution {
    private:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    } 
public:
    int maxFreqSum(string s) {
        int ovFreq = 0;
        int consFreq = 0;
        vector<int>freqTrack(26,0);

        for(auto it:s){
            freqTrack[it-'a']++;
        }

        for(int i=0;i<26;i++){
            char ch = i+'a';
            if(isVowel(ch)){
                ovFreq = max(ovFreq,freqTrack[i]);
            }
            else{
                consFreq = max(consFreq,freqTrack[i]);
            }
        }
        return ovFreq+consFreq;
    }
};