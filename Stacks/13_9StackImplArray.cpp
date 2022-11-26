
#include<bits/stdc++.h>

using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size){
        this ->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if((size - top)>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow.\n"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow.\n"<<endl;
        }
    }

    int peak(){
        if(top >=0){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
        }
        return 0;
    }

    bool empty(){
        if(top <0){
            return 1;
        }
        else{
            return 0;
        }
        return 0;
    }

};


int main(){

    Stack st(5);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(44);
    st.push(44);
    st.push(44);
    st.push(44);
    st.pop();

    cout<<st.peak()<<endl;
     st.pop();
     cout<<st.peak()<<endl;
    cout<<st.empty()<<endl;

    return 0;
}
