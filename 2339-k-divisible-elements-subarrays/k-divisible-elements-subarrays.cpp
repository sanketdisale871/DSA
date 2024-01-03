class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
  
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int cnt = 0;

            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    cnt++;
                }

                if(cnt<=k){
                    vector<int>temp;
                    for(int itr=i;itr<=j;itr++){
                        temp.push_back(nums[itr]);
                    }  

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