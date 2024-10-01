class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>um;

        for(int i=0;i<n;i++){
            int r = ((arr[i]%k)+k)%k;
            um[r]++;
        }

        for(int i=0;i<k;i++){
            if(i==0){
                if(um[i]%2!=0){
                    return false;
                }
                continue;
            }
            if(um[i]!=um[k-i]){
                return false;
            }
        }
        return true;
    }
};