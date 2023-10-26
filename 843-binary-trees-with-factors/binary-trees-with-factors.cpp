class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9+7;
        int n = arr.size();

        sort(arr.begin(),arr.end()); // Small numbers multiply get Larger Number, Vise varsa not possible

        unordered_map<int,long long int>um;

        // FOr each number there is one way
        for(auto num : arr){
            um[num]++;
        }

        for(int i=1;i<n;i++){ // Finding for each arr[i] => Total Possible ways
            long long int cnt = 0;

            for(int j=0;j<i;j++){

                if(arr[i]%arr[j]==0){ // Checking it's divisible by first number arr[j]
                    int num2 = arr[i]/arr[j]; // Second for multiplication we Want

                    if(um.find(num2)!=um.end()){ // Checking Second number not finding un map
                        cnt+=(um[arr[j]]*1ll*um[num2])%mod; // This is total number of ways to find `arr[i]` with the help of `arr[j]` and `num2`
                    }
                }
            }
            um[arr[i]]+=cnt; // For arr[i] number this is updated cnt [Total number of way to form arr[i] ]
        }

        int ans = 0;

        for(auto it : um){
            ans=(ans+it.second)%mod;
        }

        return ans;        
    }
};