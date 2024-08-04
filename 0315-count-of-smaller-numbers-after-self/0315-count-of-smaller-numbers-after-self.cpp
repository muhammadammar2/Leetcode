class FenwickTree {
private: 
    vector <int> bit;
    int n;
public:
    FenwickTree (int n) {
        this->n = n + 1;
        bit.assign(this->n , 0);
    }
    void updateBit(int index , int val) {
        while (index < n) {
            bit[index] += val;
            index += index & - index;
        }
    }
    int queryBit(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & - index;
        }
        return sum;
    }
    
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //compressed to handle smaller inputs efficiently
        vector <int> sortedNum = nums;
        sort(sortedNum.begin() , sortedNum.end());
        map<int , int> ranks;
        for (int i =0; i<sortedNum.size(); ++i) {
            ranks[sortedNum[i]] = i + 1;
        }
        
        FenwickTree ft(nums.size());
        vector <int> res(nums.size());
        
        for(int i = nums.size() -1 ; i>= 0; --i) {
            res[i] = ft.queryBit(ranks[nums[i]] - 1);
            ft.updateBit(ranks[nums[i]] , 1);
        }
        return res;
        
    }
};