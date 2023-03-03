class StockSpanner {
public:
/* Approach 1 : Monotonic Stack 
            T.C. : O(n)
            S.C. : O(n)
    
    i) Stack<pair<int,int>>st = stack<pair<price,numbers <=price>>st,
        for storing the count, how many numbers are occured upto that number
        which is less than or equal to that price.

*/
    stack<pair<int,int>>st;
    
    StockSpanner() {

        
    }
    
    int next(int price) {

        int x = 1;
        while(!st.empty() && st.top().first<=price){
            x+=st.top().second;
            st.pop();
        }
        st.push({price,x});
        return x;        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
