class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // row
        for (int i = 0; i < 9; i++) {
            bool seen[10] = {};

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                if (seen[num])
                    return false;

                seen[num] = true;
            }
        }


        //col

          for (int j = 0; j < 9; j++) {
            bool seen[10] = {};

            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                if (seen[num])
                    return false;

                seen[num] = true;
            }
        }

        // 3 cross 3

        for(int boxrow =0; boxrow<9; boxrow+=3){
            for(int boxcol =0; boxcol< 9; boxcol+=3){
                bool seen[10] ={};

                for(int i=boxrow; i<boxrow+3; i++){
                    for(int j=boxcol; j< boxcol+3; j++){

                        if(board[i][j] == '.')
                        continue;

                        int num = board[i][j] - '0';

                        if(seen[num])
                        return false;

                        seen[num] = true;
                    }
                }
            }
        }

          return true;


    }
};