class Solution {
public:
// I will 
/*
[a,b,c] ==> For every character I have the option to take it not it. 
// like this I go, 

// when I can't take, s[i]!=s[i+1];
back char 

Approach: 
i) By Duing traversing all things will generate all strings
ii) Sort it, and the will return arr[k-1]
*/ 
    vector<string>possStrings;
    void generateAllPossibleString(int ind,char prev,int n,string temp){
        
        if(ind>=n){
            possStrings.push_back(temp);
            return;
        }

        for(char ch='a';ch<='c';ch++){
            if(ch!=prev){
                temp.push_back(ch);
                generateAllPossibleString(ind+1,ch,n,temp);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        generateAllPossibleString(0,'z',n,"");

        if(possStrings.size()<k){
            return "";
        }
        sort(possStrings.begin(),possStrings.end());
        return possStrings[k-1];
    }
};