class MyStack {
    private:
    /*
    LIFO => Stack 

    FIFO => Queue
    */
    queue<int>q1;
    queue<int>q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            auto it = q1.front();q1.pop();
            q2.push(it);
        }

        q1.push(x);

        while(!q2.empty()){
            auto it = q2.front();q2.pop();
            q1.push(it);
        }
    }
    
    int pop() {
        int topElem = q1.front();q1.pop();
        return topElem;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};