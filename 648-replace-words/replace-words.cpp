class Solution {
public:
    string replaceWords(vector<string>& dict, string sen) {
        unordered_set<string>st(dict.begin(),dict.end());

        vector<string>arr;

        string res = "";

        for(auto ch:sen){
            if(ch==' '){
                arr.push_back(res);
                res = "";
            }
            else{
                res.push_back(ch);
            }
        }
        arr.push_back(res);

        string ans = "";

        for(auto it:arr){
            string r = "";
            bool isPr = 0;
            for(auto ch:it){
                r.push_back(ch);

                if(st.count(r)>0){
                    isPr = 1;
                    break;
                }
            }

            if(isPr){
                if(ans.empty()){
                    ans.append(r);
                }
                else{
                    ans.append(" "+r);
                }
            }
            else{
                if(ans.empty()){
                    ans.append(r);
                }
                else{
                    ans.append(" "+r);
                }
            }
        }

        return ans;
    }
};