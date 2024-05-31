//well the effecient approach is exclusive OR (XOR)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         unordered_set<int> u_set;
        for (int n : nums) {
            if (u_set.count(n)) {
                u_set.erase(n);
            } else {
                u_set.insert(n);
            }
        }
        
        vector<int> result(u_set.begin(), u_set.end());
        return result;
    }
};