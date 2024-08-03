class NumArray {
private: 
    int n;
    vector <int> bit;
    vector <int>& nums;
    
    void updateBit(int index , int val) {
        while (index <= n) {
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
public:
    NumArray(vector<int>& nums) : n(nums.size()) , nums(nums) , bit(n + 1 , 0) {
        for(int i=0; i<n; ++i) {
            updateBit(i + 1 , nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateBit (index + 1 , diff);
    }
    
    int sumRange(int left, int right) {
        return queryBit(right + 1) - queryBit(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */