class Solution {
    private:
    bool isVowel(char ch){
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u'){
            return true;
        }
        return false;
    }
public:
    string sortVowels(string s) {
        // string ans="";
        int len = s.length();

        /*
        1) Collect all Vowels, Capital and small both, bhaii, 
        */
        priority_queue<char,vector<char>,greater<char>>minHeap;

        for(auto it:s){
            if(isVowel(it)){
                minHeap.push(it);
            }
        }

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=minHeap.top();minHeap.pop();
            }
        }
        return s;
    }
};