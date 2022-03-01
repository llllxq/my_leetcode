class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
            
        sort(nums.begin(), nums.end());  //先排序，复杂度nlogn
        vector<vector<int>> result;
        for(int i=0; i<nums.size()-2;){  //从小到大遍历
            if(nums[i] > 0)  //已经不可能找到和为零的三元组了
                break;
            int left = i+1, right = nums.size()-1;  //左右指针
            while(left < right && nums[right] >= 0){
                if(nums[left] + nums[right] + nums[i] > 0){
                    --right;
                }
                else if(nums[left] + nums[right] + nums[i] < 0){
                    ++left;
                }
                else{
                    result.push_back({nums[left], nums[right], nums[i]});
                    ++left;
                    while(left < right && nums[left] == nums[left-1])  //防止重复
                        ++left;
                }
            }
            ++i;
            while(i<nums.size()-2 && nums[i] == nums[i-1])  //防止重复
                ++i;
        }

        return result;
    }
};
