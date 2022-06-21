class Solution {
public:
    int sum = 0;
    vector<int> table = vector<int>(37, -1);
    int tribonacci(int n) {
        if(n == 0)  return 0;
        if(n == 1 || n == 2)    return 1;
        if(table[n-1] != -1)  return table[n-1];
        
        else 
            return table[n-1] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};