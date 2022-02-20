class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numsSorted(nums);   //深拷贝
        sort(numsSorted.begin(), numsSorted.end());
        int left = 0, right = nums.size()-1; //左右指针，往中间走
        while(true)  //因为一定存在解，所以不考虑没找到的情况
        {
            if(numsSorted[left] + numsSorted[right] > target)
                --right;
            else if(numsSorted[left] + numsSorted[right] < target)
                ++left;
            else
                break;
        }
        vector<int> result;
        for(int i=0;result.size()<2;++i)
        {
            if(nums[i] == numsSorted[left])
                result.push_back(i);
            else if(nums[i] == numsSorted[right])  //加else防止两数字相同的情况出错
                result.push_back(i);
        }
        return result;
    }
};
