class Solution {
public:

    int countPrefix(int n, long long prefix)
    {
        long long offset = 10;
        long long target = n;
        int total = 0;
        for(int i=1;i<=9;i++)
        {
            long long minv = prefix * offset;
            long long maxv = minv + offset-1;
            
            
            if(target < minv)break;
            
            total+= min(target,maxv) - minv + 1;
            
            offset = offset * 10;
        }
        
        return total+1;
    }
    
    int findKthNumber(int n, int k, int prefix =0) {

     
        if(k>0)
        {
            for(int i= (prefix==0)?1:0;i<=9;i++)
            {
                int prefixCount = countPrefix(n,10*prefix+i);
                if(k<=prefixCount) return findKthNumber(n,k-1,10*prefix+i);
                k-=prefixCount;
            }            
        }
        
        return prefix;
    }
};