//left = 1 (min eating of banana)
// right = max(sorted piles)
// mid = left + (right - left) / 2;
//helper function (check min num of hours to eat bananas)
//
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin() , piles.end());
        
        while (left <= right) {
            int mid = left + (right - left) /2;
            
            if(canEatBananas (piles , mid , h)) {
                right = mid -1;
            } 
            else {
                left = mid +1 ;
            }
        }
        return left;
    }
    
    private : 
      bool canEatBananas (vector <int>& piles , int k ,int h) {
          long long hours = 0;
          
          for (int pile : piles) {
              hours += (pile + k -1 ) / k;
          }
            if (hours > h) {
                return false;
            }
          return hours <= h;
      }
};