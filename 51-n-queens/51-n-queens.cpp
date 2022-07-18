class Solution {
public:vector<vector<string>> result;
    int size;
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antidiags;
        
        backtrack(0, cols, diags, antidiags, board);
        return result;
    }
    
    void backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags,
                  unordered_set<int>& antidiags, vector<string>& board) {
        //base case
        if(row == size)    result.push_back(board);
        
        //check for every column of a particular row
        for(int col = 0; col < size; col++) {
            int Diag = row - col;
            int AntiDiag = row + col;
            
            //if queen cant be placed
            if(cols.count(col)||diags.count(Diag)||antidiags.count(AntiDiag)) {
                continue;
            }
            
            //add the queen to the board
            cols.insert(col);
            diags.insert(Diag);
            antidiags.insert(AntiDiag);
            board[row][col] = 'Q';
            
            //move to the next row
            backtrack(row+1, cols, diags, antidiags, board);
            
            //remove the queen i.e. backtrack
            cols.erase(col);
            diags.erase(Diag);
            antidiags.erase(AntiDiag);
            board[row][col] = '.';
        }
    }
};