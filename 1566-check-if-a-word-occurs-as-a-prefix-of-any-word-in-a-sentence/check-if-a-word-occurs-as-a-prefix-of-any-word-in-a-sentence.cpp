class Solution {
    private:
    bool checkPref(string &currWrd,string &srchWrd){
        int i=0,j=0;

        while(i<currWrd.length() && j<srchWrd.length()){
            if(currWrd[i]!=srchWrd[j]){
                return false;
            }
            i++;
            j++;
        }
        return j>=srchWrd.length();
    }
public:
    int isPrefixOfWord(string sen, string searchWord) {
        int ans = -1;

        int wrdCnt = 0;
        string currWrd = "";

        for(auto ch:sen){
            if(ch==' '){
                wrdCnt++;

                if(checkPref(currWrd,searchWord)){
                    ans = wrdCnt;
                     currWrd="";
                    break;
                }
                currWrd="";
            }
            else{
                currWrd.push_back(ch);
            }
        }
       

        if(currWrd!="" && checkPref(currWrd,searchWord)){
             wrdCnt++;
            ans = wrdCnt;
        }

        return ans;
    }
};