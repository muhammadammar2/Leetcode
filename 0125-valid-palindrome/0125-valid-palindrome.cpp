class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for ( char c: s){
            if (isalnum(c)){
                ss+=tolower(c);
            }
        }
        int left =0;
        int right = ss.length()-1;
        while ( left < right){
            if ( ss[left]!= ss[right]){
                return false;
            }
          left ++;
          right --;            
        }
        return true;
    }
};