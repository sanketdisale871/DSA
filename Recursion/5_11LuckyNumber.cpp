class Solution{
public:
    
    // bool solve(vector<int>&nums,int iter,int n){
        
    //     // Base condition
    //     // jr element nums madye nasel tar
      
    //     // jr iter greater than nums.size() pekha then return true
    //     if(nums.size()<iter){
            
    //     if(nums[nums.size()-1]!=n){
    //         return false;
    //     }
    //         return true;
    //     }
        
    //     int deleIndex = iter;
        
    //     // we deleteing iter wala number 
    //     while(deleIndex<nums.size()){
    //         nums.erase(nums.begin()+deleIndex);
            
    //         deleIndex+=iter;
    //     }
        
    //     solve(nums,iter+1,n);
        
        
    // }
    
    bool lucky(int n,int cuttinNumTh){
        
        // jb counter is greater than ho gaya tho n se to o lucky number hai
        if(cuttinNumTh>n){
            return true;
        }
        
        // jb remainder zero aaygi to samzo o element kat ho gaya
        if(n%cuttinNumTh==0){
            return false;
        }
        
        return lucky(n-(n/cuttinNumTh),cuttinNumTh+1);
        // luckey(ab itne element hai , counter ko ek se bada do)
    }

    bool isLucky(int n) {
        
            int cuttinNumTh = 2;
            if(lucky(n,cuttinNumTh)){
                return 1;
            }else{
                return 0;
            }
      }
};
