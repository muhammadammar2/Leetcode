class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket Sort
        unordered_map <int , int> mAp;
        for (int num : nums) {
            mAp[num]++;
        }
        int n= nums.size();
        vector <vector<int>> bucket(n + 1);
        
        for (const auto& aa : mAp) {
            int freq = aa.second;
            int num = aa.first;
            bucket[freq].push_back(num);
        }
        vector <int> res;
        for (int i = n; i>=0 && res.size() < k; --i) {
            for (int num : bucket[i]) {
                res.push_back(num);
             if (res.size() == k) break;
            }
        }
        return res;
    }
};