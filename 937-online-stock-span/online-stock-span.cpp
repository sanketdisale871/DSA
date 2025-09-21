/* Online Stock Span Problem*/
// I have to return the span of Stock bhaiii

class StockSpanner {
public:
// stack<pair<num,cnt>>
    stack<pair<int,int>>st; // I need to have the solution
    StockSpanner() {
        
    }
    
    int next(int price) {
        // Here I have to return the just ,, like this I have the 4 as the price. 
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