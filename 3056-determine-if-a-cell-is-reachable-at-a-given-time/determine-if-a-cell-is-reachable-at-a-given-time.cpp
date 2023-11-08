class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(fx-sx);
        int diffy = abs(fy-sy);

        if(diffx==0 && diffy==0 && t==1){ // Edge case
            return false;
        }

        int diaDistCover = min(diffx,diffy); // Itna common hai dono mai to mai diagonally traverse kar sakta
        int remaiDist = abs(diffx-diffy); // Now remaining distance bacha hai o, DiffX-Diffy 

        // Minimum distance to reach the destination is = "diaDistCover+remaiDist"
        // If your ""diaDistCover+remaiDist"<= t , then i can definitely will reach final destination in 't' time

        return diaDistCover+remaiDist<=t;

    }
};