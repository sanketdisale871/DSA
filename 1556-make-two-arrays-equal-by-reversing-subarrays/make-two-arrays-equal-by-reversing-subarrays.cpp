class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>freq(1e3+1,0);

        for(auto it:target){
            freq[it]++;
        }

        for(auto it:arr){
            freq[it]--;
        }

        for(int i=0;i<1e3+1;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};