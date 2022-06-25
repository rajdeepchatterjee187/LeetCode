class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && set.count(n)!=1) {
            set.insert(n);
            n = getNext(n);
        }
        return n==1;
    }
    
    int getNext(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n%10;
            sum += d*d;
            n = n/10; 
        }
        return sum;
    }
};