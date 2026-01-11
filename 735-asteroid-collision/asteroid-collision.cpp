class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int>res;
        vector<int>riArmy;
        stack<int>lefArmy;

        for(int i=n-1;i>=0;i--){
            if(ast[i]<0){
                lefArmy.push(abs(ast[i]));
            }
            else{
                
                while(!lefArmy.empty() && lefArmy.top()<ast[i]){
                    lefArmy.pop();
                }

                if(!lefArmy.empty() && lefArmy.top()==ast[i]){
                    lefArmy.pop();
                }
                else if(lefArmy.empty()){
                    riArmy.push_back(ast[i]);
                } 
            }
        }

        while(!lefArmy.empty()){
            res.push_back(-lefArmy.top());
            lefArmy.pop();
        }

        reverse(riArmy.begin(),riArmy.end());
        for(auto it:riArmy){
            res.push_back(it);
        }
        return res;
    }
};