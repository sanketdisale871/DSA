class Solution {
    private:
    vector<string>ans;

    void solve(int open,int close,string temp){
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }

        if(open>0){
            temp.push_back('(');
            solve(open-1,close,temp);
            temp.pop_back();
        }

        if(close>open){
            temp.push_back(')');
            solve(open,close-1,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(n,n,temp);

        return ans;
    }
};