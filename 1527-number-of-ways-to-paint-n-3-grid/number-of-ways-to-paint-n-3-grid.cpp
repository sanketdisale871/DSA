class Solution {
public:
    typedef long long int ll;
    const int mod = 1e9+7;
    int numOfWays(int n) {
        ll two = 6;
        ll three = 6;
        n--;


        while(n>0){
            ll nextTwo = ((3*two) + (2*three))%mod;
            three = ((2*three)+(2*two))%mod;

            two = nextTwo;
            n--;
        }

        return (two+three)%mod;
    }
};