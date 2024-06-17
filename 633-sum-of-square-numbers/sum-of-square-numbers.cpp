class Solution {
public:
    typedef long long int ll;
    bool judgeSquareSum(int c) {
        ll a = 0;
        ll b = sqrt(c);

        while(a<=b){
            ll aVal = a*a;
            ll bVal = b*b;

            if(aVal+bVal == c){
                return true;
            }
            else if(aVal+bVal < c){
                a++;
            }
            else{
                b--;
            }
        }

        return false;
    }
};