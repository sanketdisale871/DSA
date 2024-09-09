class Solution {
public:
    string convertDateToBinary(string date) {
         int yr = stoi(date.substr(0,4));
        int mon = stoi(date.substr(5,2));
        int dat = stoi(date.substr(8,2));

        string res = "";

        string t = "";
        while(yr){
            if(yr&(1<<0)){
                t.push_back('1');
            }
            else{
                t.push_back('0');
            }

            yr>>=1;
        }
        reverse(t.begin(),t.end());
        t.push_back('-');
        
        res+=t;
        t = "";

        while(mon){
            if(mon&(1<<0)){
                t.push_back('1');
            }
            else{
                t.push_back('0');
            }

            mon>>=1;
        }
        reverse(t.begin(),t.end());
         t.push_back('-');
        
        res+=t;
        t = "";
        while(dat){
             if(dat&(1<<0)){
                t.push_back('1');
            }
            else{
                t.push_back('0');
            }

            dat>>=1;
        }
        reverse(t.begin(),t.end());
        res+=t;

        return res;
    }
};