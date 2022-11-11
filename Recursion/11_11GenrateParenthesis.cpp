vector<string>ans;

void solve(string temp,int open,int close){
    
    // Base case
    if(open==0 && close==0){
        ans.push_back(temp);
        return;
    }
    
    // choice of open bracket available when it's available
    if(open>=0){
        temp+='(';
        solve(temp,open-1,close);
        temp.pop_back();
    }
    
     // choice of close bracket available when it's available and close>open
    if(close>open){
        temp+=')';
        solve(temp,open,close-1);
        temp.pop_back();
    }
    
    
}


vector<string> Solution::generateParenthesis(int A) {
    
    int open = A;
    int close = A;
    string temp ="";
    
    solve(temp,open,close);
    
    return ans;
}
