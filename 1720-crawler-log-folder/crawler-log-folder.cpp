class Solution {
public:
    int minOperations(vector<string>& logs) {
        int crntDr = 0;

        for(auto it:logs){
            if(it=="../"){
                if(crntDr>0){
                    crntDr--;
                }
            }
            else if(it=="./"){
                continue;
            }
            else{
                crntDr++;
            }
        }
        return crntDr;
    }
};