class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char , int> freqS;
        unordered_map <char , int> freqT;
        
        for (char ss : s) {
            freqS[ss]++;
        }
        for (char tt : t) {
            freqT[tt]++;
        }
        return freqS == freqT;
    }
};