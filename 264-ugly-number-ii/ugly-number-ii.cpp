class Solution {
public:
    typedef long long int ll;
    int nthUglyNumber(int n) {
        set<ll>st;

        ll nthNumer =1;

        st.insert(nthNumer);

        for(ll i=0;i<n;i++){
            nthNumer = *st.begin();

            st.erase(nthNumer);
            st.insert(nthNumer*2);
            st.insert(nthNumer*3);
            st.insert(nthNumer*5);
        }
        return nthNumer;
    }
};