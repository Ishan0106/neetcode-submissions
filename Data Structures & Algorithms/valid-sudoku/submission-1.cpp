class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> box(9,vector<int>(9,0));


        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue; 
                }

                int val = board[r][c] - '1'; 
                int boxIdx = (r / 3) * 3 + (c / 3);

                if (row[r][val] || col[c][val] || box[boxIdx][val]) {
                    return false;
                }

                row[r][val] = true;
                col[c][val] = true;
                box[boxIdx][val] = true;
            }
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isposs(vector<vector<char>>& board , int i , int j , char k){
        for(int l = 0 ; l < 9 ; l++){
            if(board[i][l] == k)return false;
            else if(board[l][j] == k)return false;
            else if(board[3*(i/3)+l/3][3*(j/3)+l%3] == k)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.size() ; j++){
                if(board[i][j] == '.'){
                    for(char k = '1' ; k <= '9' ; k++){ 
                        if(isposs(board,i,j,k)){
                            board[i][j] = k;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         if(solve(board) == true){
            return true;
         }
         return false;
    }
};

*/