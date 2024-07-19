class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string , vector<string>> gA;
        for (string s : strs) {
            string So = s;
            sort(So.begin(), So.end());
            gA[So].push_back(s);
        }
        vector<vector<string>>res;
        for(auto it : gA) {
            res.push_back(it.second);
        }
        return res;
    }
};