class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);

            if(st.size()==1 && st.top()=='0'){
                st.pop();
            }
        }

        // for increasing number case
        while(k && !st.empty()){
            st.pop();
            k--;
        }

        // making the answer from stack numbers
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        if(ans.size()==0){
            return "0";
        }
        return ans;      

    }
};