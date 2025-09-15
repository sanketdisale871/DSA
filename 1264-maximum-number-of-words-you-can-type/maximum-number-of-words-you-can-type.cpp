class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>brknLetters(brokenLetters.begin(),brokenLetters.end());

        int wrdCnt = 0;
        bool isbrknLetter = false;
        string wrd = "";

        for(int i=0;i<text.length();i++){
            wrd.push_back(text[i]);

            if(brknLetters.count(text[i])){
                isbrknLetter = true;
            }

            if(text[i]==' '){
                if(!isbrknLetter){
                    wrdCnt++;
                }
                isbrknLetter = false;
                wrd="";
            }
        }
        
        if(!isbrknLetter){
                    wrdCnt++;
        }

        return wrdCnt;
    }
};