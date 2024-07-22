class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> ms;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = ms.top(); ms.pop();
                int a = ms.top(); ms.pop();
                
                if (t == "+") ms.push(a + b);
                else if (t == "-") ms.push(a - b);
                else if (t == "*") ms.push(a * b);
                else if (t == "/") ms.push(a / b);
            }
            else {
                ms.push(stoi(t));
            }
        }
        return ms.top();
    }
};