class Solution {
    private:
    unordered_map<char,string>um=
    {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string>ans;

    void solve(int ind,string temp,string digits){
        // Base case
        if(ind>=digits.length()){
            ans.push_back(temp);
        }

        string word = um[digits[ind]];

        for(int i=0;i<word.length();i++){
            solve(ind+1,temp+word[i],digits);
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        if(digits.length()==0){
            return ans;
        }

        string temp="";

        solve(0,temp,digits);

        return ans;
    }
};