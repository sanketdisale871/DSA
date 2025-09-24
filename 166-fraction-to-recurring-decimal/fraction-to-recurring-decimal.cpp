class Solution {
public:
unordered_map<int,int>um; 
;
    string fractionToDecimal(int num, int den) {
        bool neg = (num<0)^(den<0) ? true: false;
        long long int n = num;
        long long int d = den;
        n = abs(n);
        d = abs(d);
        long long int tmp = n/d;
        string res = "";
        if(neg && n!=0)
         res += "-";

        res += to_string(tmp);
        n %= d;
        if(n==0){
            return res;
        }
        res += ".";
        // now before decimal, work is over now after decimal
        bool repeat = false;
        unordered_map<long long int, int> mp; // mapping from remainder to size of string
        while(n!=0 && !repeat){
            if(mp.find(n)==mp.end())
                mp[n] = res.size(); // mp[n]=res.size();
            else if(mp.find(n)!=mp.end()){
                // repeat found
                repeat = true; // no need of repeat variable as we are breaking explicitly
                res.push_back(')');
                res.insert(mp[n],"(");
                break;
            }
            n = n*10;
            res += to_string(n/d);
            n %= d;
        }
        return res;
    }
};