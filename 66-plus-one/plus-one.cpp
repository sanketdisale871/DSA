class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int car = 1;

        for(int i=digits.size()-1;i>=0;i--){
            int currRes = digits[i]+car;
            int dig = currRes%10;
            car = currRes/10;

            res.push_back(dig);
        }
        if(car){
            res.push_back(car);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};