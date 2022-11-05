void placeAtRightPosi(int num,stack<int>&st){
    
    // Base condition
    
    if(st.empty() || st.top()<=num){
        st.push(num);
        return;
    }
    
    int elem = st.top();
    st.pop();
    
    placeAtRightPosi(num,st);
    
    st.push(elem);
    
}

void sorting(stack<int>&st){
     // Base case
     if(st.empty()){
         return;
     }
     
     int num = st.top();
     st.pop();
     
     sorting(st);
     
     placeAtRightPosi(num,st);
     
}

void SortedStack :: sort()
{
   sorting(s);
   
   
}
