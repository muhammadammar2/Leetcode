class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> res (n , 0);
        stack <int> s;
        
        for (int i =0; i<n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int ii = s.top();
                s.pop();
                res[ii] = i - ii; 
            }
            s.push(i);
        }
        return res;
    }
};