class Solution {
    private:
    typedef long long int ll;
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        else if(n==2){
            return "11";
        }
        else{

            string s = "11";

            for(ll i=3;i<=n;i++){
                string t = "";
                s=s+'$';

                ll cnt = 1;

                for(ll j=1;j<s.length();j++){

                    if(s[j]==s[j-1]){
                        cnt++;
                    }
                    else{
                        t = t + to_string(cnt);
                        t = t+s[j-1];
                        cnt=1;
                    }
                }
                s = t;
            }
            return s;

        }
    }
};