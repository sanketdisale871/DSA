class Solution {
public:
    bool isCircularSentence(string sentence) {
        char prev =' ';

        bool isSpace = 0;
        for(auto ch:sentence){
            if(ch==' '){
                isSpace = 1;
            }
            else if( isSpace && ch!=prev){
                return false;
            }
            else if(ch!=' '){
                prev = ch;
                isSpace = 0;
            }
        }
        
        return sentence[0]==prev;
    }
};