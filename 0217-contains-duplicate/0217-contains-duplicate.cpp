class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> u_set;
        for (int c : nums) {
            if (u_set.count(c) > 0) return true;
            u_set.insert(c);
        }
        return false;
    }
};