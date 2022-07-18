class Solution {
public:
    int ans;
    int size;
    
    int totalNQueens(int n) {
        size = n;
        
        
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antidiags;
        
        backtrack(0, cols, diags, antidiags);
        return ans;
    }
    
    void backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags,
                  unordered_set<int>& antidiags) {
        //base case
        if(row == size)    ans++;
        
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
            
            
            //move to the next row
            backtrack(row+1, cols, diags, antidiags);
            
            //remove the queen i.e. backtrack
            cols.erase(col);
            diags.erase(Diag);
            antidiags.erase(AntiDiag);
            
        }
    }
};