class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        unordered_map<int,int>um;
        stack<int>st;
        st.push(-1);

        int secArraySize = nums2.size();

        for(int i=secArraySize-1;i>=0;i--){
            while(st.top()!=-1 && st.top()<nums2[i]){
                st.pop();
            }
            um[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        /*
        nums2 = [1,3,4,2]               n = 4
                 0 1 2 3 
                 3 4 -1 -1              Stack Wali chiz hai bhaii: [3,4,-1]
        */

        for(int i=0;i<nums1.size();i++){
            ans.push_back(um[nums1[i]]);
        }

        return ans;
    }
};