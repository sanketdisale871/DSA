class Solution {
    // DSA Student : Sanket Disale
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int>ans;
        deque<int>dq;

        int n = arr.size();

        for(int i=0;i<n;i++){
            // checking out off window
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }

            // mainting the decreasing order deque
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            // pushing index into deque

            dq.push_back(i);

            
            if(i>=k-1){ // at this point window contain 'k' elements
                ans.push_back(arr[dq.front()]);
            }

        }
        return ans;
    }
};
