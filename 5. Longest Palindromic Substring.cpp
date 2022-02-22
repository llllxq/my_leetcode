class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int left = 0, right = 0; //左右索引
        while(right < s.length()){
            int bias = 0;
            while(true){
                if(left - bias >= 0 && right + bias < s.length() &&  //没有越界
                    s[left - bias] == s[right + bias]){  //且是回文
                    ++bias;
                }
                else{
                    --bias;
                    if(2*bias + right - left + 1 > result.length()){
                        result = s.substr(left - bias, 2*bias + right - left + 1);
                    }
                    break;
                }
            }

            if(left == right){  //先走一步right，再走left，再走right，循环
                ++right;
            }
            else{
                ++left;
            }
        }
        return result;
    }
};
