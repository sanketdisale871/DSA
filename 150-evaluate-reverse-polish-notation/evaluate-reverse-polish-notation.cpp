class Solution {
public:
    typedef long long int ll;
    int evalRPN(vector<string>& tokens) {
        stack<ll>st;

        for(auto it:tokens){

            if(it=="+"){
                ll e2 = st.top();st.pop();
                ll e1=st.top();st.pop();

                st.push(e1+e2);
            }
            else if(it=="-"){
                ll e2 = st.top();st.pop();
                ll e1=st.top();st.pop();

                st.push(e1-e2);
            }
            else if(it=="*"){
                ll e2 = st.top();st.pop();
                ll e1=st.top();st.pop();

                st.push(e1*e2);
            }
            else if(it=="/"){
                ll e2 = st.top();st.pop();
                ll e1=st.top();st.pop();

                st.push(e1/e2);
            }
            else{
                ll num = stoi(it);
                st.push(num);
            }
        }
        return st.top();
    }
};