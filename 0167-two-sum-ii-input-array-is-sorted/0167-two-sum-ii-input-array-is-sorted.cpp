class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        
        while (left < right){
            int currSum = numbers[left] + numbers[right];
            
            if (currSum < target) left+= 1;
            else if (currSum > target) right-=1;
            else {
                return vector<int> {left+1 , right+1};
            }
          
        }
        return vector<int> {};
    }
};