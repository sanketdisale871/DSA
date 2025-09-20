class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Just next greater elment I have to find re
        stack<int>st;
        int n = nums2.size();
        vector<int>ans;
        st.push(-1);

        // Here I will map the 
                  // Num, Greater 
        unordered_map<int,int>um;
        
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && st.top()<nums2[i]){
                st.pop();
            }
            um[nums2[i]]=st.top();

            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(um[nums1[i]]);
        }
        return ans;
    }
};