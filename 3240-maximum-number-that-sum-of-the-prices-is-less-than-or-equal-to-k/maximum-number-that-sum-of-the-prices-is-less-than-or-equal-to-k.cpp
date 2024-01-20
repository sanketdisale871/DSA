#define ll long long
ll a[100];
class Solution {
public:
    
    void solve(ll n){
        if(n==0) return;
        if(n==1){
            a[0]++;
            return;
        }
        if(n==2){
            a[0]++;
            a[1]++;
            return;
        }
        ll bitlen= log2(n);
        ll no=(1ll<<bitlen);
        a[bitlen]+=(n-no+1);

        for(int i=0;i<bitlen;i++){
            a[i]+=(no/2);
        }
        n=n-no;
        solve(n);
    }
    long long findMaximumNumber(long long k, int x) {

        ll i=0,j=1e17;        
        while(i<=j){
            ll m=(i+j)/2;
            for(int i=0;i<100;i++) a[i]=0; 
            solve(m);
            ll ans=0;
            for(int i=0;i<100;i++){
                if((i+1)%x==0) ans+=a[i];
            }
            if(ans<=k){
                i=m+1;
            }
            else{
                j=m-1;
            }
            
        }
        return i-1;
    }
};
// code by ObviouslyBhavya