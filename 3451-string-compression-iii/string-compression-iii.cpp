class Solution {
public:
    string compressedString(string word) {
        char currch =  ' ';
        int cnt = 0;
        string ans = "";

        for(auto ch:word){

            if(ch!=currch){
                if(currch!=' ' && cnt!=0){
                    ans.push_back(cnt+'0');
                    ans.push_back(currch);
                }
                currch = ch;
                cnt=1;
            }
            else if(ch==currch){
                cnt++;
            }

            if(cnt>=9){
                ans.push_back(cnt+'0');
                ans.push_back(currch);
                cnt = 0;
            }
        }

        if(cnt>=1){
            ans.push_back(cnt+'0');
            ans.push_back(currch);
        }
        return ans;
    }
};