class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>cmPrf;

        for(auto it:arr1){
            int num = it;

            while(num){
                cmPrf[num]=1;
                num/=10;
            }
        }

        int ans = 0;

        for(auto it:arr2){
            int num = it;
            while(num){
                if(cmPrf.find(num)!=cmPrf.end()){
                    string str = to_string(num);
                    int len = str.length();
                    ans = max(ans,len);
                    break;
                }
                num/=10;
            }
        }

        return ans;
    }
};