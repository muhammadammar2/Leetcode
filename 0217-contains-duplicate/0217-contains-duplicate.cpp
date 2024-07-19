class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>Set;
        for (int n : nums) {
            if (Set.count(n) > 0) return true;
            Set.insert(n);
        }
        return false;
    }
};