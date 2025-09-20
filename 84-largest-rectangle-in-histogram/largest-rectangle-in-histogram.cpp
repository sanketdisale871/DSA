class Solution {
    private:
    vector<int>lmaxim(vector<int>& h){
        int n = h.size();

        vector<int>lmax(n);
        stack<int>st;
        st.push(-1);

        for(int i=0;i<n;i++){

            while(st.top()!=-1 && h[st.top()]>=h[i]){
                st.pop();
            }

            lmax[i]=st.top();

            st.push(i);
        }

        return lmax;
    }

    vector<int>rmaxim(vector<int>& h){
        int n = h.size();

        vector<int>rmax(n);
        stack<int>st;
        st.push(n);

        for(int i=n-1;i>=0;i--){
            
            while(st.top()!=n && h[st.top()]>h[i]){
                st.pop();
            }

            rmax[i]=st.top();

            st.push(i);
        }

        return rmax;
    }


public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>lmaxi = lmaxim(heights);
        vector<int>rmaxi = rmaxim(heights);

        int maxArea = 0;

        for(int i=0;i<n;i++){
            int bre = (rmaxi[i]-lmaxi[i])-1;
            int ht = heights[i];
            int area = bre*1ll*ht;
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};