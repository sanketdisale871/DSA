class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        vector<int>temp;

        stack<int>left;

        int n = ast.size();

        for(int i=n-1;i>=0;i--){
            if(ast[i]<0){
                left.push(abs(ast[i]));
            }
            else{
                int r = ast[i];

                while(!left.empty() && r>=1){
                    if(left.top()>r){
                        r=0;
                    }
                    else if(left.top()==r){
                        r=0;
                        left.pop();
                    }
                    else{
                        left.pop();
                    }
                }

                if(r>=1){
                    temp.push_back(r);
                }
            }
        }

        while(!left.empty()){
            ans.push_back(-left.top());
            left.pop();
        }

        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }

        return ans;
    }
};