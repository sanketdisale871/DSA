class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        stack<int>starsInd;
        stack<int>open;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                starsInd.push(i);
            }
            else{
                if(open.empty() && starsInd.empty()){
                    return false;
                }

                if(!open.empty()){
                    open.pop();
                }
                else if(!starsInd.empty()){
                    starsInd.pop();
                }
            }
        }

        while(!open.empty() && !starsInd.empty() && open.top()<starsInd.top()){
            open.pop();
            starsInd.pop();
        }

        if(open.empty()){
            return true;
        }
        return false;
    }
};