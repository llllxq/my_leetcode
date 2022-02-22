class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size()) / 2;  //找两个数组中第k小的数
        if ((nums1.size() + nums2.size()) % 2 != 0)  //奇数位，多加一位，因为/2向下取整了
            ++k;
        int i1 = 0, i2 = 0;  //num1,num2当前索引

        while (k > 1) {  // k == 1 时跳出循环
            /*if (i1 + k / 2 - 1 >= nums1.size()) {
                i2 =  i2 + k/2 - (nums1.size() - i1);
                i1 = nums1.size();
            }
            else if (i2 + k / 2 - 1 >= nums2.size()) {
                i1 = i1 + k/2 - (nums2.size() - i2);
                i2 = nums2.size();
            }*/
            if (i1 + k / 2 - 1 >= nums1.size()) {
                if (i1 < nums1.size()) {
                    if (nums1[i1] < nums2[i2])
                        ++i1;
                    else
                        ++i2;
                    --k;
                }
                else {
                    i2 = i2 + k / 2;
                    k -= k / 2;   //不能直接 k /= 2，会因为向下取整出错
                }
            }
            else if (i2 + k / 2 - 1 >= nums2.size()) {
                if (i2 < nums2.size()) {
                    if (nums1[i1] < nums2[i2])
                        ++i1;
                    else
                        ++i2;
                    --k;
                }
                else {
                    i1 = i1 + k / 2;
                    k -= k / 2;   //不能直接 k /= 2，会因为向下取整出错
                }
            }
            else {
                if (nums1[i1 + k / 2 - 1] < nums2[i2 + k / 2 - 1]) {
                    i1 += k / 2;
                }
                else {
                    i2 += k / 2;
                }
                k -= k / 2;
            }
             
        }

        double median = 0;
        if ((nums1.size() + nums2.size()) % 2 == 0) {  //偶数位数
            if (i1 == nums1.size())
                median = 0.5 * (nums2[i2 + 1] + nums2[i2]);
            else if (i2 == nums2.size())
                median = 0.5 * (nums1[i1 + 1] + nums1[i1]);
            else {
                if (nums1[i1] < nums2[i2]) {
                    if(i1 + 1 < nums1.size())  //考虑越界
                        median = 0.5 * (nums1[i1] + min(nums1[i1 + 1], nums2[i2]));
                    else
                        median = 0.5 * (nums1[i1] + nums2[i2]);
                }
                else {
                    if(i2 + 1 < nums2.size())
                        median = 0.5 * (nums2[i2] + min(nums1[i1], nums2[i2 + 1]));
                    else
                        median = 0.5 * (nums1[i1] + nums2[i2]);
                }
            }

        }
        else {  //奇数位数
            if (i1 == nums1.size())
                median = nums2[i2];
            else if (i2 == nums2.size())
                median = nums1[i1];
            else
                median = min(nums1[i1], nums2[i2]);
        }
        return median;
    }
};
