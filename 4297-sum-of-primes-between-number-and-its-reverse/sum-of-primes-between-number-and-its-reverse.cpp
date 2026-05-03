class Solution {
    private:
    int findRevNum(int num){
        int revNum = 0;

        while(num){
            int dig = num%10;
            num/=10;

            revNum=revNum*10+dig;
        }
        return revNum;
    }

    bool isPrime(int num){
        if(num==1){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
public:
    typedef long long int ll;
    int sumOfPrimesInRange(int n) {
        int r = findRevNum(n);
        ll sumPrimeNums = 0;

        for(int i=min(n,r);i<=max(n,r);i++){
            if(isPrime(i)){
                sumPrimeNums+=(i*1ll);
            }
        }
        return sumPrimeNums;
        
    }
};