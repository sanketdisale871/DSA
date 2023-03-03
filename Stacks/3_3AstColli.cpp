class Solution {
public:
/*  Approach : T.C : O(n)
                S.C : O(n)
    Intuition : 
     According to the question, positive values are moving to the right and negative values are moving to the left. We can apply the concept of relative velocity and make positive values as fixed and negative values now moving with double velocity in the negative direction. But, magnitude of velocity does not matter only the direction matters.

*  Lets see how to use this idea to code.

    Consider the same example [8, 9, 6, -7, -9, 12, 50, -34]
    Initially i = 0.

    1) Whenever we encounter a positive value, we will simply push it to the stack.
    2)  The moment we encounter a negative value, we know some or all or zero positive values   will be knocked out of the stack. The negative value may itself be knocked out or it may enter the stack. 
    3) We will keep on poping the elements from the stack while the asteroids[i] > s.top(). But remember, negative asteroids can never pop another negative asteroids, since they will never meet them. So, the final condition is while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])), we will pop the elements.

    4) We have to take care of the case when s.top() == asteroids[i]. In this case one positive element will pop out and negative asteroid won't enter the stack.
    5) If after knocking out elements stack becomes empty() or s.top() becomes negative, that means the current asteroids[i] will enter the stack. 
*/
    vector<int> asteroidCollision(vector<int>& ast) {

        stack<int>st;
        int n = ast.size();

        for(int i=0;i<n;i++){
            if(st.empty() || ast[i]>0){
                st.push(ast[i]);
            }
            else{
                while(!st.empty() and st.top()>0 and st.top()<abs(ast[i])){
                    st.pop();
                }

                if(!st.empty() and st.top()==abs(ast[i])){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top()<0){
                        st.push(ast[i]);
                    }
                }
            }
        }

        vector<int>ans(st.size());

        for(int i = (int)st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;

        
    }
};
