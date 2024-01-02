class Solution {
    private:
    vector<string>ans;
    unordered_map<int,string>um= {
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };

    void solve(int ind,string &digits,string temp){
        if(ind >= digits.size()){
            ans.push_back(temp);
            return ;
        }

        int digit = digits[ind]-'0';
        string res = um[digit];

        for(int i=0;i<res.length();i++){

            solve(ind+1,digits,temp+res[i]);

        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Edge case
        if(digits.size()==0){
            return ans;
        }

        string temp ="";
        solve(0,digits,temp);
        return ans;
    }
};