#define pii pair<int,int>
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pii, vector<pii>, greater<pii>> busy, avl;
        vector<int> ans;
        int timer = 0;
        for(int i=0;i<servers.size();i++)
            avl.push({servers[i],i});        
        for(int i=0;i<tasks.size();i++){
            if(avl.empty())
                timer = busy.top().first;            
            while(!busy.empty() && busy.top().first<=timer){
                int j = busy.top().second;
                avl.push({servers[j],j});
                busy.pop();
            }            
            int k = avl.top().second;
            avl.pop();
            ans.push_back(k);
            busy.push({timer + tasks[i],k});
            timer = max(timer,i+1);
        }
        return ans;        
    }
};