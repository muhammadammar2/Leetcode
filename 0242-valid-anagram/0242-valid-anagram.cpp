class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char , int> freqS;
       unordered_map<char , int> freqT;
       for (int ss: s){
        freqS[ss]++;
       }
       for (int tt : t){
        freqT[tt]++;
       }
       return freqS==freqT;
    }
};