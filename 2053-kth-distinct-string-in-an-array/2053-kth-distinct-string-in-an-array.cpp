class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map <string , int> uMap;
        for (auto & ch : arr) 
            uMap[ch]++;
        for (auto & ch : arr) 
            if (uMap[ch] == 1 && --k == 0)
                return ch;
        return "";
    }
};