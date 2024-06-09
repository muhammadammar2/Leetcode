class Solution {
public:
    bool isValid(string s) {
        stack <char> myStack;
        for (char ch : s) {
            if ( ch == '(' || ch == '{' || ch == '[') {
                myStack.push(ch);
            }
            else {
                if (myStack.empty()){
                    return false;
                }
                
                char top = myStack.top();
                myStack.pop();
                
                  if ( (ch == ')' && top!= '(') || 
                   (ch == '}' && top!= '{') ||
                      (ch == ']' && top!= '[')
                     ) {
                      return false;
                  }                 
            }
        }
        return myStack.empty();
    }
};