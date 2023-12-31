class Solution {
    private:
    bool isSingleChar(int i,int j,string &str){
        char prev = str[i];
        i++;
        for(;i<=j;i++){
            if(str[i]!=prev){
                return false;
            }
        }
        return true;
    }
public:
    int maximumLength(string s) {
        int n = s.length();
        
        unordered_map<string,int>um;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isSingleChar(i,j,s)){
                    um[s.substr(i,(j-i+1))]++;
                }
                else{
                    break;
                }
            }
        }
        
        
        for(auto it:um){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<endl;
        
        int maxLen = -1;
        
        for(auto it:um){
            if(it.second >2){
                int len = it.first.length();
                cout<<"Len : "<<len<<endl;
                if(len>maxLen){
                    maxLen = len;
                }
                // maxLen = max(maxLen,);
            }
        }
        return maxLen;
    }
};