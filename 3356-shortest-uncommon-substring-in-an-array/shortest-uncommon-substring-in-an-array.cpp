class Solution {
public:
    typedef long long int ll;
    vector<string> shortestSubstrings(vector<string>& arr) {
        // 1) Genration of all substrings
        // 2) checking by genrating all substring 

        ll n = arr.size();
        
        map<string,unordered_set<ll>>um;

         vector<string>ans(n);
        
        
        for(ll itr=0;itr<arr.size();itr++){
            string it = arr[itr];
            for(ll i=0;i<it.length();i++){
                string res = "";
                for(ll j=i;j<it.length();j++){
                   res.push_back(it[j]);


                    bool isFound = false;


                    for(int si=0;si<arr.size();si++){
                        if(si!=itr){
                            if(arr[si].find(res) != string::npos){
                                isFound = true;
                            }
                        }
                    }

                    if( (!isFound) && (ans[itr].empty() || ans[itr].length()>res.length() || (ans[itr].length()==res.length() && ans[itr]>res))){
                        ans[itr]=res;
                    }
                }
            }
        }
        return ans;
    }
};