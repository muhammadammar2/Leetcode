typedef long long ll;
const int MOD = 1e9 + 7;

class FenwickTree {
public:
    vector<ll>bit;
    int n;
    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(this->n , 0);
    }
    void updateBit(int index , ll val) {
        while (index < n){
            bit[index] += val % MOD;
            index += index & - index;
        }
    }
    ll queryBit(int index) {
        ll sum = 0;
        while (index > 0) {
            sum += bit[index] % MOD;
            index -= index & - index;
        }
        return sum;
    }
    ll queryRange(int left , int right) {
        return (queryBit(right) - queryBit(left - 1) + MOD) % MOD;
    }
};
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector <ll> subSum;
        for (int i = 0; i<n; ++i) {
            ll sum = 0;
            for (int j = i; j<n; ++j) {
                sum += nums[j];
                subSum.push_back(sum);
            }
        }
        sort(subSum.begin() , subSum.end());
        
        FenwickTree ft(subSum.size());
        for(int i=0; i<subSum.size(); ++i) {
            ft.updateBit(i + 1 , subSum[i]);
        }
        return ft.queryRange(left , right);
    }
};