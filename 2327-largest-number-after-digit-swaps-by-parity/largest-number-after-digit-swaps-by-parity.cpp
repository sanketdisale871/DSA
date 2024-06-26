class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> p; 
        priority_queue<int> q; 
        string nums=to_string(num);
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int digit=nums[i]-'0'; 
            if((digit)%2) 
                p.push(digit);
            else
                q.push(digit); 
        }
        
        int answer=0;
        for(int i=0; i<n; i++){
            answer=answer*10;
            if((nums[i]-'0')%2)
                {answer+=p.top();p.pop();}
            else
                {answer+=q.top();q.pop();} 
        }
        return answer;
    }
};