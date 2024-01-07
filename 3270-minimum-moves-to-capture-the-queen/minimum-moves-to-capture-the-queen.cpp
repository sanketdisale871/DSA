class Solution {
    /*
    **Approach**

A] Max possilbe move is 2. What ever is the configuration, queen can be captured in 2 moves

B] Now when ever the two pieces are head to head and the third pice is not in between them then we can capture queen in 1 step. This can be possible in 4 different ways :
a) rook and queen in same row
b) rook and queen in the same column
c) bishop and queen in the same anti- diagonal
d) bishop and queen in the same diagonal

C] Only check for above four cases along with the check that the 3rd piece is not in between two direct capture.   

How to identify the bishop is in between of Rook and Queen : 

i) in Horizontal way & Vertical way : (B-R)*(B-Q) < 0 Means Bishop is between of R and Q
II0 

*/
public:                          // a       b        c        d      e       f 
  int minMovesToCaptureTheQueen(int Rr, int Rc, int Br, int Bc, int Qr, int Qc) {
      // For Rook Wala Approach
    if(Rr == Qr || Rc == Qc){
        if(Rr == Br &&((Bc-Rc)*(Bc-Qc)<0)){ // in between row sie
            return 2;
        }
        if(Rc==Bc && ((Br-Rr)*(Br-Qr)<0)){
            return 2;
        }
        return 1;
    }
    // For Bishop Wala Approach 
    if(abs(Qr-Br) == abs(Qc-Bc)){
        if(abs(Rr-Br)==abs(Rc-Bc) && ((Rc-Bc)*(Rc-Qc))<0){
            return 2;
        }
        return 1;
    }

    return 2;
}
};