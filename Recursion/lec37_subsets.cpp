class Solution {
    private :
    
    void solve(vector<int>& nums,vector<int>temp,int index, vector<vector<int>>&ans){
        // base call
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        
        // exclude wali recutsive call
        solve(nums,temp,index+1,ans);
        
        // include wali recursive call
        
        int element = nums[index];
        temp.push_back(element);
        solve(nums,temp,index+1,ans);
        
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        int index = 0;
        
        solve(nums,temp,index,ans);
        return ans;
    }
};

int main(){
int n;cin>n;
  vector<int>nums;
  for(int i=0;i<n;i++){
    int d;cin>>d;nums.push_back(d);
  }
  vector<vector<int>>Subsets = subsets(nums);
  
  for(int i=0;i<Subsets.size();i++){
    for(int j=0;j<Subsets[i].size();j++{
      cout<<Subsets[i][j]<<" ";
    }
        cout<<endl;
}
        
  
return 0;
}
