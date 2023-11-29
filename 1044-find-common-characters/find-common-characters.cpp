class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        for(auto ch : words[0]){

            int j;
            for(j=1;j<n;j++){
                auto it = words[j].find(ch);

                if(it == string::npos){
                    break;
                }
                words[j].erase(it,1);
            }

            if(j==n){
                ans.push_back(string(1,ch));
            }
        }
        return ans;
    }
};