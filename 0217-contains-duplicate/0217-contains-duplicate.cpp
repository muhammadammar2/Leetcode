class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> u_set;
        for (int n : nums) {
            if (u_set.count(n) > 0) return true;
            u_set.insert(n);
        }
       return false;
    }
};