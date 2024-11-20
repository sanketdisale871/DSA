class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;

        vector<int>rght;
        stack<int>left;

        int n = ast.size();

        for(int i=n-1;i>=0;i--){
            if(ast[i]<0){
                left.push(abs(ast[i]));
            }
            else{

                while(!left.empty() && left.top()<ast[i]){
                    left.pop();
                }

                if(!left.empty() && left.top()==ast[i]){
                    left.pop();
                }
                else if(left.empty()){
                    rght.push_back(ast[i]);
                }           

            }
        }

        while(!left.empty()){
            ans.push_back(-left.top());
            left.pop();
        }

        for(int i=rght.size()-1;i>=0;i--){
            ans.push_back(rght[i]);
        }

        return ans;
    }
};