class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        if(k>=n){
            return *max_element(arr.begin(),arr.end());
        }

        deque<int>dq;

        for(auto it : arr){
            dq.push_back(it);
        }

        int cnt=0,prev = -1;
        while(1){
            int num1 = dq.front();dq.pop_front();
            int num2 = dq.front();dq.pop_front();

            int maxi = max(num1,num2);

            if(maxi == prev){
                cnt++;
                if(cnt == k){
                    return maxi;
                }
            }
            else{
                prev = maxi;
                cnt = 1;

                if(cnt == k){
                    return maxi;
                }
            }

            if(maxi==num1){
                dq.push_front(num1);
                dq.push_back(num2);
            }
            else{
                dq.push_front(num2);
                dq.push_back(num1);
            }

        }

        return -1;
    }
};