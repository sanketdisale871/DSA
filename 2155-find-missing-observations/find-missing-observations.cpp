class Solution {
public:
typedef long long int ll;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans;

        int totLen = rolls.size() + n;

        
        ll r = totLen * mean;
        ll totSum = accumulate(rolls.begin(),rolls.end(),0);

        ll f = r - totSum;

        cout<<"f : "<<f<<endl;

        bool isOdd = f%n==0?false:true;

        for(int i=0;i<n;i++){
            int val = f/n;
            if(val>6 || val<=0){
                return {};
            }
            ans.push_back(f/n);
        }

        ll rem = f%n;

        for(ll i=0;i<n;i++){
            if(rem>0){
                if(ans[i]<6){
                    int dalSakta = 6-ans[i];

                    if(rem<dalSakta){
                        ans[i]+=rem;
                        rem = 0;

                    }
                    else{
                        ans[i]+=dalSakta;
                        rem-=dalSakta;
                    }
                    

                    
                }
            }
        }

        if(rem>0){
            return {};
        }

        return ans;

    }
};