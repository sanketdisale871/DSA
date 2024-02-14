class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x == y) return 0;
        // if(x < y) return y-x;
        
        int operations = 0;
        queue<int> q;
        q.push(x);
        unordered_set<int> visited;
        
        while(!q.empty()) {
            int len = q.size(); 
            
            for(int i = 0; i < len; i++) {
                int a = q.front(); 
                q.pop();
                if(visited.find(a) != visited.end())
                    continue;
                visited.insert(a);
                
                if(a == y)
                    return operations;
                if(a%11 == 0)
                    q.push(a/11);
                if(a%5 == 0)
                    q.push(a/5);
                q.push(a+1);
                q.push(a-1);
            }
            operations++;
        }
        
        return -1;
    }
};