class Solution {
public:

    vector<string>ans;

    void solve(string &s,string &temp,int index){

        // Base case
        if(index==s.length()){
            ans.push_back(temp);
            return;
        }

        // checking it's digit or not if not digit the capitalize this letter
        if(isdigit(s[index])){
            temp.push_back(s[index]);
            solve(s,temp,index+1);
            temp.pop_back();
        }else{

             /* First choice to capitalize the given letter*/

            // char uppch = s[index] & '_';
            char uppch = toupper(s[index]);
            temp.push_back(uppch);
            solve(s,temp,index+1);
            temp.pop_back();

            /* Second choice to lowerize the given letter*/

            // char lowch = s[index] | ' ';
            char lowch = tolower(s[index]);
            temp.push_back(lowch);
            solve(s,temp,index+1);
            temp.pop_back();

        }

        //    // checking it's digit or not if not digit the lowerise this letter
        // if(s[index]>='0' && s[index]<='9'){
        //     temp.push_back(s[index]);
        //     solve(s,temp,index+1);
        //     temp.pop_back();
        // }else{
        //     char lowch = s[index] | ' ';
        //     temp.push_back(lowch);
        //     solve(s,temp,index+1);
        //     temp.pop_back();
        // }

    }

    vector<string> letterCasePermutation(string s) {
        
        int index =0;
        string temp ="";

        solve(s,temp,0);

        return ans;
    }
};
