class Solution {
    private:
    vector<vector<string>>ans;

    bool isPalindrome(int l,int h,string s){
        while(l<=h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }

    void solve(int ind,string s,int n,vector<string>temp){
        // base case 
        if(ind>=n){
            ans.push_back(temp);
            return ;
        }

        for(int i=ind;i<n;i++){
            if(isPalindrome(ind,i,s)){
                string res = s.substr(ind,i-ind+1);
                temp.push_back(res);
                solve(i+1,s,n,temp);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;
        
        solve(0,s,s.length(),temp);

        return ans;
    }
};