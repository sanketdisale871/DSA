class Solution {
    private:
    vector<vector<string>>ans;

    bool isPalindrome(int l,int r,string s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(int ind,string s,vector<string>&temp){
        // Base case 
        if(ind>=s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<s.length();i++){
            if(isPalindrome(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));

                solve(i+1,s,temp);

                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;

        solve(0,s,temp);

        return ans;
    }
};