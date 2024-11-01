class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";


        for(int i=0;i<s.length();i++){
            if(ans.length()>=2 && ans.back()==s[i] && ans[ans.length()-2]==s[i]){
                continue;
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};