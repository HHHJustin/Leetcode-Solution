bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    for(int i=0;i<9;i++){
        int check[9] = {0};
        for(int j=0;j<9;j++){
            if(board[i][j]<='9' && board[i][j]>='1'){
                if(check[board[i][j] - '0' - 1]==1){return false;}
                check[board[i][j]-'0'-1] = 1;
            }
        }
    }

    for(int i=0;i<9;i++){
        int check[9] = {0};
        for(int j=0;j<9;j++){
            if(board[j][i]>='1' && board[j][i]<='9'){
                if(check[board[j][i]-'0'-1]==1){return false;}
                check[board[j][i]-'0'-1] = 1;
            }
        }
    }

    for(int i=0;i<9;i++){
        int check[9] = {0};
        for(int j=0;j<9;j++){
            if(board[(i/3)*3 + j/3][(i%3)*3 + j%3] >= '1' && board[(i/3) * 3 + j/3][(i%3)*3 + j%3]<='9'){
                if(check[board[(i/3)*3 + j/3][(i%3)*3 + j%3]-'0'- 1] == 1){return false;}
                check[board[(i/3)*3 + j/3][(i%3)*3 + j%3]-'0'- 1] = 1;
            }
        }
    }
    return true;
}

// give a matrix (Sudoku). check it if a validated.
// need to following rules.
// 1. Each row must contain the digits 1-9 without repetition.
// 2. Each column must contain the digits 1-9 without repetition.
// 3. Each nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// use 1 array[9] -> record the ever appear number.
// solve 1. -> check board[i][1-9]
// solve 2. -> check board[1-9][i]
// solve 3. -> check board[3i + 1-3][3j + 1-3]
// 
// [[0, 0, 0, 0, 0, 0, 0, 0, 0]]     -> [[0, 0, 0],   ->[[0, 0, 0],     (x / 3)
// [[1, 1, 1, 1, 1, 1, 1, 1, 1]]         [1, 1, 1],      [1, 1, 1],
// [[2, 2, 2, 2, 2, 2, 2, 2, 2]]         [2, 2, 2]]      [2, 2, 2]]
// [[3, 3, 3, 3, 3, 3, 3, 3, 3]]
// [[4, 4, 4, 4, 4, 4, 4, 4, 4]]
// [[5, 5, 5, 5, 5, 5, 5, 5, 5]]
// [[6, 6, 6, 6, 6, 6, 6, 6, 6]]
// [[7, 7, 7, 7, 7, 7, 7, 7, 7]]
// [[8, 8, 8, 8, 8, 8, 8, 8, 8]]

// [[0, 1, 2, 3, 4, 5, 6, 7, 8],     -> [[0, 1, 2],  -> [[3, 4, 5],      (x % 3)
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],         [0, 1, 2],      [3, 4, 5],
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],         [0, 1, 2]]      [3, 4, 5]]
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],
// [[0, 1, 2, 3, 4, 5, 6, 7, 8],
// [[0, 1, 2, 3, 4, 5, 6, 7, 8]]

// if repeat -> return false.
