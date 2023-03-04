class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char>st;

        for(int i=0;i<n;i++){           

            while(k && !st.empty() && st.top()>num[i]){
            // if k greater than 0 and our stack is not empty and the upcoming digit,
            // is less than the current top than we will pop the stack top
                st.pop();
                k--;
            }
            st.push(num[i]);

             // popping preceding zeroes, case -> num = "10200"
            if(st.size() == 1 && st.top() == '0'){
                st.pop();
            }
        }

       // for cases ascending string num, like 1234, we have to pop from end of string
        while(!st.empty() && k){
            st.pop();
            k--;
        }

        // Making answer from stack element
        string ans ="";
       
        while(!st.empty()){
        //    ans = st.top()+ans; this get more time hence solution give TLE 
            ans.push_back(st.top());
            st.pop();
        }
            reverse(ans.begin(),ans.end());

            if(ans.length() == 0){
               return "0";
            }
            return ans;           
        
    }
};
