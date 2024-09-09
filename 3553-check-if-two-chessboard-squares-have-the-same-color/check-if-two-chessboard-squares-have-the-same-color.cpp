class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int col1 = coordinate1[0] - 'a' + 1;
    int row1 = coordinate1[1] - '0';
    int col2 = coordinate2[0] - 'a' + 1;
    int row2 = coordinate2[1] - '0';

    
    bool color1 = (col1 + row1) % 2 == 0;
    bool color2 = (col2 + row2) % 2 == 0;


    return color1 == color2;
    }
};