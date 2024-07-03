class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector <string> result;
        string current;
        unordered_map<char , string> mapping = {
            {'2' , "abc"} , {'3' , "def"} , {'4' , "ghi"} , {'5' , "jkl"} , {'6' , "mno"} , {'7' , "pqrs"} , 
            {'8' , "tuv"} , {'9' , "wxyz"}
        };
        
        backtrack(result , current , digits , 0 , mapping);
        return result;
    }
private:
   void backtrack (vector<string>& result , string& current , const string& digits, int index , const unordered_map<char , string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
       char digit = digits[index];
       const string& letters = mapping.at(digit);
       
       for (char letter : letters) {
           current.push_back(letter);
           backtrack(result , current , digits , index + 1 , mapping);
           current.pop_back();
       }
    }
    
};