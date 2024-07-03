class Solution {
private: 
    void backtrack(vector<int>& candidates , int target , int start , vector<int>& current , vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i<candidates.size(); ++i) {
            if (i  > start && candidates[i] == candidates[i -1]) {
                continue;
            }
        current.push_back(candidates[i]);
            
        backtrack(candidates , target - candidates [i] , i+1 , current , result);
        current.pop_back();
            }    
    }
            
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <int> current;
        vector <vector <int>> result;
        sort(candidates.begin() , candidates.end());
        backtrack(candidates , target , 0 , current , result);
        return result;
    }
};