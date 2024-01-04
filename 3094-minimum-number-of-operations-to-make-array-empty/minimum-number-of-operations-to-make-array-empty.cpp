class Solution {
    /*
    Algorithm and approach : 
    1) freq => 1  || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10
       Oper => -1 || 1 || 1 || 2 || 2 || 2 || 3 || 3 || 3 || 4

       oper = ceil[(freq)/3.0]
    
    */
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>um;

        for(auto num : nums){
            um[num]++;
        }

        int cnt = 0;
        
        for(auto it : um){
            if(it.second == 1){
                return -1;
            }
            cnt+= ceil(it.second/3.0);
        }
        return cnt;
    
    }
};