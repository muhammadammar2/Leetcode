class Solution {
private:
    void backtrack(vector<int>& candidates , int target , int start, vector<int>& current , vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i<candidates.size(); ++i) {
            current.push_back(candidates[i]);
            // i below ensures the unique combinations not duplicate otherwise wouldve went for 0
            backtrack (candidates , target - candidates[i] , i , current , result);
            
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int>> result;
        vector<int> current;
        backtrack(candidates , target , 0 , current , result);
        return result;
    }
};