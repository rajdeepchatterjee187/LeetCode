class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> nge(n);
        stack<int> stack;
        
        for(int i = n-1; i >= 0; i--) {
            while(!stack.empty() and temp[stack.top()] <= temp[i])
                stack.pop();
            if(stack.empty())
                nge[i] = -1;
            else
                nge[i] = stack.top();
            stack.push(i);
        }
        
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            if(nge[i] > 0)
                result[i] = nge[i] - i;
            else
                result[i] = 0;
         }
        
        return result;
    }
};