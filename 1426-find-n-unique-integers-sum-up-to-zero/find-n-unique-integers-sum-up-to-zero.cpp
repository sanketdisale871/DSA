class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>stAns;
        
        if(n&1){
            stAns.push_back(0);
            n--;
        }

        int num = 1;

        for(int itr=1;itr<=n;itr+=2){
            stAns.push_back(num);
            stAns.push_back(-num);
            num++;
        }
        return stAns;
    }
};