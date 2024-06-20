class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // by using maps (still effecient)
        // unordered_set <int> u_set;
        // for (int n : nums) {
        //     if (u_set.find(n) != u_set.end()) {
        //         return n;
        //     }
        //     u_set.insert(n);
        // }
        // return -1;
        
        //Flodys tortoise and hare Algo
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);
        
        slow = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        } 
        return slow;
    }
};