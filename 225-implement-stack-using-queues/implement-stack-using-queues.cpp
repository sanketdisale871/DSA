class MyStack {
public:
    queue<int>q;
    MyStack() {
        // like this all came towards us
       
    }
    
    void push(int x) {
        q.push(x);
        int siz = q.size()-1;
        while(siz--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        auto it = q.front();q.pop();
        return it;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */