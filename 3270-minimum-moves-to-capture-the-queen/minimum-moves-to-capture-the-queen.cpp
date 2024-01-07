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
*/
public:                          // a       b        c        d      e       f 
  int minMovesToCaptureTheQueen(int Rr, int Rc, int Br, int Bc, int Qr, int Qc) {
      // For Rook Wala Approach
    if(Rr == Qr || Rc == Qc){
        if(Rr == Br &&((Bc-Rc)*(Bc-Qc)<0)){ // Bishop row mai bich mai aa raha hai
            return 2;
        }
        if(Rc==Bc && ((Br-Rr)*(Br-Qr)<0)){ // Bishop col mai bich mai aa raha hai 
            return 2;
        }
        return 1;
    }
    // For Bishop Wala Approach : Bishop kb Ek move mai reach kar sakata hai Queen ko ?
    if(abs(Qr-Br) == abs(Qc-Bc)){ // diagonal hai ma Bishop and Queen 
        if(abs(Rr-Br)==abs(Rc-Bc) && ((Rc-Bc)*(Rc-Qc))<0){ // Rook bich mai aa raha hai
            return 2;
        }
        return 1;
    }
    return 2;
}
};