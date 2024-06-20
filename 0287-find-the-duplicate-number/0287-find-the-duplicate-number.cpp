class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> u_set;
        for (int n : nums) {
            if (u_set.find(n) != u_set.end()) {
                return n;
            }
            u_set.insert(n);
        }
        return -1;
    }
};