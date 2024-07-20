class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set <int> numSet (nums.begin(), nums.end());
        int longestS = 0;
        
        for(int num : numSet) {
            //check if its the start of a seq
            if (numSet.find(num - 1) == numSet.end()) {
                int currentS = 1;
                int currentNum = num;
                
                //capture the longest seq
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum ++;
                    currentS ++;
                }
                longestS = max (longestS , currentS);
            }
        }
        return longestS;
    }
};