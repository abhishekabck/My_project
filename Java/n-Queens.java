class Solution {
    public Boolean isSafe(int row, int col, char[][] board) {
        // Horizontal
        for(int c = 0; c < board.length; c++){
            if (board[row][c] == 'Q') {
                return false;
            }
        }

        // Vertical check
        for(int r = 0; r < board.length; r++) {
            if (board[r][col] == 'Q') {
                return false;
            }
        }

        //Upward left
        for(int r = row, c = col; c >= 0 && r >= 0; c--, r--) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }

        // upward right
        for(int r = row, c = col;  c < board.length && r>=0; c++, r--) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }

        // lower left
        for(int r = row, c = col; c >= 0 && r < board.length; c--, r++) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }

        // lower right
        for(int r = row, c = col;  c < board.length && r < board.length; c++, r++) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }

        return true;
    }

    public void saveBoard(char[][] board, List<List<String>> allBoards) {
        String row = "";
        List<String> newBoard = new ArrayList<>();
        for(int i = 0; i < board.length; i++) {
            row = "";
            for (int j =0; j<board[0].length; j++) {
                if (board[i][j] == 'Q')
                    row += 'Q';
                else 
                    row += '.';
            }
            newBoard.add(row);
        }
        allBoards.add(newBoard);
    }

    public void helper(char[][] board, List<List<String>> allBoards, int col) {
        if (col == board.length) {
            saveBoard(board, allBoards);
            return;
        }
        for(int row = 0; row<board.length; row++) {
            if(isSafe(row, col, board)) {
                board[row][col] = 'Q';
                helper(board, allBoards, col+1);
                board[row][col] = '.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];
        List<List<String>> allBoards = new ArrayList<>();

        helper(board, allBoards, 0);
        return allBoards;
    }
}