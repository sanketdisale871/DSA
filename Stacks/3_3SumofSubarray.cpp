class Solution {
public:
const int mod = 1e9+7;
/* Approach 1 : Generating Subarrays and finding minimum
                T.C. : O (n^2)
                S.C. : O (1)
    
*/
/*
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
       long minSum = 0;
        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            for(int j=i;j<n;j++){
                mini = min(mini,arr[j]);
                minSum=(minSum+mini)%mod;
            }
        }
        return minSum;
    }
*/

/* Approach 2 : think about each element in the array and in how many subarrays that element will be minimum.
                T.C. : O (n)
                S.C. : O (n)
    
*/
    int sumSubarrayMins(vector<int>& arr){
        int n = arr.size();
 stack <pair<int,int>> s1,s2;
        vector <int> l;
        vector <int> r (n);
        for(int i=0;i<n;i++)
        {
            int x=0;
            while(!s1.empty() && arr[i]<=s1.top().first)
            {
                x+=s1.top().second+1;
                s1.pop();
            }
            l.push_back(x);
            s1.push({arr[i],x});
        }
        for(int i=n-1;i>=0;i--)
        {
            int x=0;
            while(!s2.empty() && arr[i]<s2.top().first)
            {
                x+=s2.top().second+1;
                s2.pop();
            }
            r[i]=x;
            s2.push({arr[i],x});
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(((l[i]+1)*1LL*(r[i]+1))*1LL*arr[i]);
            ans%=mod;
        }
        return ans;

     }


};
