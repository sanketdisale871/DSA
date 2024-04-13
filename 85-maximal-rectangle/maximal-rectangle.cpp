class Solution {
    // DSA Student : Sanket Disale
public:

    int calArea(vector<int>&arr){
        int n = arr.size();
        vector<int>nextSmall(n),prevSmall(n);
        stack<int>st;
        st.push(-1);
        // Finding next smaller
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nextSmall[i]=st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        st.push(-1);

        // Finding Prev smaller
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            prevSmall[i]=st.top();
            st.push(i);
        }

        // Calculating maxArea
        int maxArea = INT_MIN;

        for(int i=0;i<n;i++){
            int len = arr[i];

            if(nextSmall[i]==-1){
                nextSmall[i]=n;
            }
            int b = nextSmall[i]-prevSmall[i]-1;

            maxArea = max(maxArea,len*b);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int>v(cols,0);

        int maxArea = INT_MIN;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    v[j]+=1;
                }
                else{
                    v[j]=0;
                }
            }
            int area = calArea(v);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};