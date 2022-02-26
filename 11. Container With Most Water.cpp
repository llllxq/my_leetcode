class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1; //左右指针
        int maxNum = 0;

        while(left < right){
            if(height[left] < height[right]){  //每次都移动短板，这样就不会错过最大值
                maxNum = max((right - left) * height[left], maxNum);
                ++left;
            }
            else{
                maxNum = max((right - left) * height[right], maxNum);
                --right;
            }
        }

        return maxNum;
    }
};
