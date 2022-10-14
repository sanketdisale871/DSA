// Using Recurssion

class Solution {
public:
    int fib(int n) {
        
        if(n==0){ // Base Case
            return 0;
        }
        if(n==1){ // Base Case
            return 1;
        }
        
        int first = fib(n-1); //recursive call
        int second = fib(n-2);//recursive call
        
        return first+second ; // return value
      
      
      // Using For loop 
      
           if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int pvspvs = 0;
        int pvs = 1;
        
        int next = 0;
        for(int i=0;i<=(n-2);i++){
            next = pvspvs + pvs ;
            
            pvspvs = pvs;
            pvs = next ;
        }
        
        return next;
        
        
    }
};


