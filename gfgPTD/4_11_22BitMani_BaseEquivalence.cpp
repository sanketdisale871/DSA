class Solution {
public:
string baseEquiv(int n, int m){

// Approach = in every base we are checkin given number written how many digits
 
// base range given 2 - 32
for(int i=2;i<=32;i++){

int digit =0;
int value = n;

while(value>0){
  // digits badegi
digit++;
value/=i;
}

if(digit==m){
return "Yes";
}
}
return "No";
}
};
