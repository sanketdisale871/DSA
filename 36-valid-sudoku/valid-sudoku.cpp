class Solution {
    /*
  From Tier4 se I can go to the Tier 1 companies, toh, aur kya chahiye. hahahaha

  Don't loose Swanket hopes, You need only one chance. Prepare aise karunga na, ki ek hi chance mai
  nikal jayega.   
    */
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> row(9, 0);
    vector<int> col(9, 0);
    vector<int> boxes(9, 0);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') // board[i][j]!='.'
            {
                //  board[i][j] = 5-'0' => 5,, 1<<5 => 32
                int bit = 1 << (board[i][j] - '0');
                //5th BIT i settled
                int index = i/3 * 3 + j / 3 ; // 
                if(row[i]&bit || col[j]&bit || boxes[index]&bit)
                    return false;
                row[i] |= bit ; // row[i]|=bit
                col[j] |= bit ; // col[j]|=bit
                boxes[index] |= bit ; // boxes[index]|=bit. boxes of index i setteled.
         }
     }
     return true;
  }
};