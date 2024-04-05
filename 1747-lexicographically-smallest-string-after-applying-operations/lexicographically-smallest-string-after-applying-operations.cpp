class Solution {
    private:
    string perAddOper(string s,int a){
       for (int i=1; i<s.length(); i += 2) {
            char &c = s[i];
            c = '0' + (c-'0'+a)%10;
        }
        return s;
    }

    string perRotOper(string s,int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());

        return s;
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        unordered_set<string>st;
        queue<string>q;
        q.push(s);
        st.insert(s);

        while(!q.empty()){
            auto it = q.front();q.pop();

            ans = min(ans,it);

            string addOper = perAddOper(it,a);
            string rotOper = perRotOper(it,b);

            if(st.count(addOper)==0){
                q.push(addOper);
                st.insert(addOper);
            }

            if(st.count(rotOper)==0){
                q.push(rotOper);
                st.insert(rotOper);
            }
        }

        return ans;
    }
};