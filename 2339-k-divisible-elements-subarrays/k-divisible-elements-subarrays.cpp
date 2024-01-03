class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
  
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            vector<int>temp;
            int cnt = 0;

            for(int j=i;j<n;j++){
                
                if(nums[j]%p==0){
                    cnt++;
                }

                temp.push_back(nums[j]);

                if(cnt<=k){
                    st.insert(temp);
                }
                else{
                    break;
                }
            }
        }
        return st.size();
    }
};