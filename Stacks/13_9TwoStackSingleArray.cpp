#include<bits/stdc++.h>

using namespace std ;

class Stack{
    public:
    int size;
    int *arr;
    int top1;
    int top2;

    Stack(int s){
        this->size = s;
        top1=-1;
        top2=s;
        arr = new int[s];
    }

    void push1(int elem){
        if((top2-top1)>1){
            top1++;
            arr[top1]=elem;
        }
    }

    void push2(int elem){
        if((top2-top1)>1){
            top2--;
            arr[top2]=elem;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }
    int pop2(){
        if(top2<size){
            int ans = arr[top2];
            top2--;
            return ans;
        }
        else{
            return -1;
        }
    }

};

int main(){

    Stack st(6);
    st.push1(78);
    st.push1(745);
    


    return 0;
}

