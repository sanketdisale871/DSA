class Solution {
public:
    int minimumTimeToInitialState(string wordd, int k) {
       string word = wordd;
        int t =0;
        string temp = "";

        for(int i=0;i<k;i++){
            temp.push_back('~');
        }

        while(!word.empty() && word[0]!='~'){

            word.erase(word.begin(),word.begin()+k);
            word = word+temp;
            t++;

            // Compare
            int i=0;
            for(;i<wordd.length();i++){
                if(word[i]=='~'){
                    continue;
                }
                else if(wordd[i]==word[i]){
                    continue;
                }
                else{
                    break;
                }
            }

            if(i>=wordd.length()){
                break;
            }

            // cout<<"wrpd  : "<<word<<endl;
            // t++;
        }
        return t; 
    }
};