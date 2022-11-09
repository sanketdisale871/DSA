class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(int i,int j,string &s){
        
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;         
            }
        }
        return true;
    }
    
    void solve(string &s,int index,vector<string>&path){
        
        // base case
        
        if(index==s.length()){
            ans.push_back(path);
            return;
        }
        
        // looping the string for partition 
        
        for(int i=index;i<s.length();i++){
            
            if(isPalindrome(index,i,s)){
                // path mai partition ki hui string push karo
                path.push_back(s.substr(index,i-index+1));
                // agle i+1 ke liye call karo
                solve(s,i+1,path);
                // jate samay add ki huye string ko push karo
                path.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string>path;
        int index = 0;
        
        solve(s,0,path);
        
        return ans;
    }
};
