class Solution {
public:
    int getLucky(string s, int k) {
        string num="";
        for(auto ch:s){
            int dig = int(ch-'a')+1;
            // str.push_back(char(ch-'a'+1));
            num+=to_string(dig);
        }

        cout<<"NUm :"<<num<<endl;

        while(k--){
            int res = 0;
            for(auto it:num){
                res+=(it-'0');
            }
            num = to_string(res);
        }
        
        int res = stoi(num);
        return res;
    }
};