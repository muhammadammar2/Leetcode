class Solution {
private: 
    void backtrack(vector<int>& nums , vector<bool>& used , vector<int>& current , vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums , used , current , result);
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> current;
        vector <bool> used (nums.size() , false);
        vector <vector<int>> result;
        backtrack(nums , used , current , result);
        return result;
    }
};