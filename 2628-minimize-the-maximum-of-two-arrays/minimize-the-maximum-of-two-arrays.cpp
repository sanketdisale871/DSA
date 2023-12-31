class Solution {
    private:
    typedef long long int ll;

    ll gcd(ll a,ll b){
        if(a%b == 0){
            return b;
        }
        return gcd(b,a%b);
    }

    ll lcm(ll d1,ll d2){
        ll g = gcd(d1,d2);

        cout<<"GCD : "<<g<<endl;

        ll res = (d1/g)*d2;
        cout<<"LCM : "<<res<<endl;
        return res;
    }

    bool checkPossible(ll m,ll d1,ll d2,ll uc1,ll uc2,ll lcmm){
        ll e1 =m-(m/d1); // Not divisible by d1 
        ll e2=m-(m/d2); // Not divisible by d2 
        // LCM : Lowest Common Multiple of ( d1,d2 )
        ll c = m-(m/d1)-(m/d2)+(m/lcmm);
        // c => The element who does not divisible by d1,d2 
        // Reason behind adding -> Common element which are not divisible by d1,d2 are substracted two times, so for this adding  
        // m/cmmm -> No.of whose divisibe by (d1,d2)
        return e1>=uc1 && e2>=uc2 && (uc1+uc2 <= (e1+e2-c));

        // e1+e2-c => Not divisible by d1 + Not divisible by d2 - (Not divisibel by d1,d2 becoz, it substracted two times adding once )
    }

public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        ll low = 0;
        ll high = INT_MAX;

        ll lcmm=lcm(d1,d2);

        ll ans = 0;

        while(low<=high){
            ll mid = low + (high-low)/2;

            if(checkPossible(mid,d1,d2,uc1,uc2,lcmm)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};