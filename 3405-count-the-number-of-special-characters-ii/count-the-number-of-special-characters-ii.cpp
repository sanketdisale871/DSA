class Solution {
public:
    int numberOfSpecialChars(string word) {
        // lowercase occurance should appear before the first occurance
        // firstLowerCaseOccurance, 
        // firstUppercase occurance
        // ek hi bar change goga
        int cnt = 0;
        vector<int>lstOccurLowerCase(26,-1);
        vector<int>fstOccurUpperCase(26,-1);

        for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(ch>='a' && ch<='z'){
                lstOccurLowerCase[ch-'a']=i;
            }
            else{
                if(fstOccurUpperCase[ch-'A']==-1){
                    fstOccurUpperCase[ch-'A']=i;
                }
            }
        }

        for(int i=0;i<26;i++){
            if(lstOccurLowerCase[i]!=-1 && fstOccurUpperCase[i]!=-1 && lstOccurLowerCase[i]<fstOccurUpperCase[i]){
                cnt++;
            }
        }
        return cnt;
    }
};