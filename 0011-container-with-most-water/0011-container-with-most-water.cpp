// area = width * height 
//width = difference of right and left (right - left)
// height = pointers (height [left] , height [right])
// keep the track of max area u get so far 

class Solution {
public:
    int maxArea(vector<int>& height) {
     int left = 0;
        int right = height.size()-1;
        int res=0;
        
        while (left < right ) {
            int area = (right - left ) * min (height[left] , height [right]);
            
            res = max (res, area);
            
            if ( height[left] < height [right]){
                left ++;
            }
            else {
                right --;
            }
        }
        return res;
    }
};