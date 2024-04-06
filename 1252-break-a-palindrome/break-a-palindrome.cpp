class Solution {
    private:
    typedef long long int ll;
    bool isPalindrome(string t){
        ll l = 0;
        ll h = t.length()-1;
        
        while(l<h){
            if(t[l]!=t[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
}

public:
    string breakPalindrome(string str) {
        string newStr = str;

        if(str.length()==1){
            return "";
        }
    
        for(ll i=0;i<str.length();i++){
            for(char ch='a';ch<str[i];ch++){
                newStr[i]=ch;
                if(!isPalindrome(newStr)){
                    return newStr;
                }
            }
            newStr[i]=str[i];
        }

        for(ll i=str.length()-1;i>=0;i--){
            char ch = str[i];
            ch++;
           
            newStr[i]=ch;
            if(!isPalindrome(newStr)){
                return newStr;
            }
            
            newStr[i]=str[i];
        }




        return "";
    }
};