class Solution {
    // DSA Student : Sanket Disale

    /* Algorithm : T.C : O(rows*cols)*O(nextSmaller)+O(prevSmaller)+O(calculating Area)
    S.C. : O(3*cols) -> storing the nextSmaller,PrevSmaller Elements

    1) Calculate the area of each row in matrix.
    2) moving to next row, add the prev row into next row
    
    */

    vector<int> nextSmall(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        st.push(-1);

        vector<int>nextSmaller(n);

        for(int i = n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nextSmaller[i]=st.top();
            st.push(i);
        }
        return nextSmaller;
    }

    vector<int> prevSmall(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        st.push(-1);

        vector<int>prevSmaller(n);

        for(int i = 0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            prevSmaller[i]=st.top();
            st.push(i);
        }
        return prevSmaller;
    }

    int calArea(vector<int>&arr){
        int n = arr.size();
        vector<int>nextSmaller(n);
        nextSmaller = nextSmall(arr);

        vector<int>prevSmaller(n);
        prevSmaller = prevSmall(arr);

        int maxArea = 0;

        for(int i = 0;i<n;i++){
            int len = arr[i];

            if(nextSmaller[i]==-1){
                nextSmaller[i]=n;
            }

            int breadth = nextSmaller[i]-prevSmaller[i]-1;

            int area = len*1LL*breadth;

            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea = 0;

        vector<int>histogram(cols,0);
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    histogram[j]+=1;
                }
                else{
                    histogram[j]=0;
                }
            }
            maxArea = max(maxArea,calArea(histogram));
        }
        
        return maxArea;
    }
};
