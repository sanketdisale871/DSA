class Solution {
public:
    int minimumTimeToInitialState(string ori, int k) {
       string word = ori;

        int t =0;

        while(!word.empty() && word[0]!='~'){
            
            // Erasing the first 'k' characters
            // word.erase(word.begin(),word.begin()+k);
            word = word.substr(k) + string(k,'~');
            t++;

            // Compare the tow string
            int i=0;
            for(;i<ori.length();i++){
                // if(word[i]=='~'){
                //     continue;
                // }
                // else if(wordd[i]==word[i]){
                //     continue;
                // }
                // else{
                //     break;
                // }

                /* One Condition */
                if(word[i]!='~' && word[i]!=ori[i]){
                    break;
                }
            }

            if(i>=ori.length()){
                break;
            }
        }
        return t; 
    }
};