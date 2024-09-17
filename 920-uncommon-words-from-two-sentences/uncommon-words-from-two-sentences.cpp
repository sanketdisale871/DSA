class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;

        unordered_map<string,int>st1;
        unordered_map<string,int>st2;

        /*
        First Sent : Freq => 1 , Freq => 0
        */
        string wrd = "";

        for(auto ch:s1){
            if(ch==' '){
               st1[wrd]++;
                wrd="";
            }
            else{
                wrd.push_back(ch);
            }
        }
        st1[wrd]++;

        wrd = "";

        for(auto ch:s2){
            if(ch==' '){
                st2[wrd]++;
                wrd = "";
            }
            else{
                wrd.push_back(ch);
            }
        }
        st2[wrd]++;

        for(auto it:st1){
            if(it.second ==1 && st2[it.first]==0){
                ans.push_back(it.first);
            }
        }
        for(auto it:st2){
            if(it.second ==1 && st1[it.first]==0){
                ans.push_back(it.first);
            }
        }

        

        return ans;
    }
};