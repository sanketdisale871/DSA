class Solution {
    private:
    int findCuts(int len,int siz){
        return len/siz;
    }
    bool isPossible(int len,string s,int numOps){
        int n = s.length();
        int i=0;
        int cnt1=0;
        int cnt0=0;
        int cuts = 0;

        if(len==1){
            int st = 0;
            int cut1=0;
            for(int j=0;j<n;j++){
                if(s[j]-'0'== (!st)){
                    st = !st;
                }
                else{
                    cut1++;
                    st = !st;
                }
            }

            st = 1;
            int cut2=0;
            
            for(int j=0;j<n;j++){
                if(s[j]-'0'== (!st)){
                    st = !st;
                }
                else{
                    cut2++;
                    st = !st;
                }
        }
        cuts = min(cut1,cut2);


        }
        else{
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                cnt0++;
                int res = findCuts(cnt1,len+1);
                cuts+=res;

                cnt1=0;
            }
            else{
                cnt1++;
                int res = findCuts(cnt0,len+1);
                cuts+=res;
                cnt0=0;
            }
        }
        if(cnt1>0){
           int res = findCuts(cnt1,len+1);
                cuts+=res; 
        }
        else if(cnt0>0){
            int res = findCuts(cnt0,len+1);
                cuts+=res;
        }
        cout<<"Cuts : "<<cuts<<"  Len : "<<len<<endl;
        }

       
        return cuts<=numOps;
    }
public:
    int minLength(string s, int numOps) {
        int low=1;
        int high = s.length();
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,s,numOps)){
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