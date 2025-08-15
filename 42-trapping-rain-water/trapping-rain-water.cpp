class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int water = 0;

        int maxLeft = height[left];
        int maxRight = height[right];

        while(left<right){
            if(height[left] <= height[right]){
                left++;
                maxLeft = max(maxLeft,height[left]);
                water += (maxLeft - height[left]);
            }
            else{
                right--;
                maxRight = max(maxRight,height[right]);
                water += (maxRight-height[right]);
            }
        }
        return water;
    }
};
