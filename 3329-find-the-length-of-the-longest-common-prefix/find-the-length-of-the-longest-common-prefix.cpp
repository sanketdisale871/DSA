class Solution {
    private:
    typedef long long int ll;
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ll ans = 0;
    
        unordered_map<ll,ll>um; // => prefix of arr1
        
        for(auto it:arr1){
            ll num = it;
            while(num){
                um[num]=1;
                num/=10;                
            }            
        }       
        
        for(auto it:arr2){ //Checking the prefix of arr2 exists in arr1 or NOT.
            ll num = it;
            while(num){    
                if(um[num]==1){ 
                   string res = to_string(num);
                    if(res.length()>ans){
                        ans = res.length();
                    }
                    break; // length to decrese honi wali hai
                }
                num/=10;                
            }    
        }    

        return ans;
    }
};