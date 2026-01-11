class Solution {
    private:

    vector<int>findNexSmaller(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int>st;
        st.push(-1);

        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }

        return res;
    }

    vector<int>findPrevSmaller(vector<int>arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int>st;
        st.push(-1);

        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }

        return res;
    }

    int findArea(vector<int>arr){
        vector<int>prevSmaller = findPrevSmaller(arr);
        vector<int>nexSmaller = findNexSmaller(arr);
        int maxiArea = 0;
        for(int i=0;i<arr.size();i++){
            int len = arr[i];
            int br = (nexSmaller[i]==-1?arr.size():nexSmaller[i]) - prevSmaller[i]-1;

            int currArea = len*br;
            maxiArea = max(maxiArea,currArea);
        }
        return maxiArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxiArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int>arr(cols,0);

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    arr[j]+=1;
                }
                else{
                    arr[j]=0;
                }
            }

            int currArea = findArea(arr);
            maxiArea = max(maxiArea,currArea);
        }


        return maxiArea;

    }
};