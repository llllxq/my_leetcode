class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 && s.length() == 1)
            return s.length();
        int left = 0, right = 0;  //子串左右索引
        unordered_set<char> subSet;
        int maxLen = 0;
        while(right < s.length()){
            if(subSet.find(s[right]) == subSet.end()){  //不重复
                if(right - left + 1 > maxLen){  //记录最长子串长度
                    maxLen = right - left + 1;
                }
                subSet.insert(s[right]);
            }
            else{  //重复
                if(right - left > maxLen){  //记录最长子串长度
                    maxLen = right - left;
                }
                while(s[left] != s[right]){  //找到重复字符的索引
                    subSet.erase(s[left]);  //删除重复元素之前的子串
                    ++left;
                }
                ++left;  //还要额外加一次
            }
            ++right;
        }
        return maxLen;
    }
};
