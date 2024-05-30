class Solution {
public:
    bool isPalindrome(string s) {
        string newStr;
        for (char c : s) {
            if (isalnum(c)){
                newStr += tolower(c);
            }
        }
        int left = 0;
        int right = newStr.size()-1;
        
        while(left < right) {
            if (newStr [left] != newStr [right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};