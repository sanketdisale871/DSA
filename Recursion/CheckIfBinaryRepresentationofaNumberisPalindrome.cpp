#include <bits/stdc++.h> 

bool rcheckPalindrome(vector<int>&bits,int i,int j){
    
    if(i>j){
        return true;
    }    
    if(bits[i]!=bits[j]){
        return false;
    }
    else{
        i++;
        j--;
        return rcheckPalindrome(bits,i,j);
    }
    
}

bool checkPalindrome(long long N)
{
    vector<int>bits;
    
    while(N!=0){
        long long bit = N&1;
        bits.push_back(bit);
        N=N>>1;
    }
    
   return rcheckPalindrome(bits,0,bits.size()-1);

}
