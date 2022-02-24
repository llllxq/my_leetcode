class Solution {
public:
    int myAtoi(string s) {
        int index = 0;  //索引
        int sign = 1;  //符号
        int result = 0;  //结果

        while(index < s.length() && s[index] == ' ')
            ++index;

        if(index < s.length()){
            if(s[index] == '-'){
                sign = -1;
                ++index;
            }
            else if(s[index] == '+')  //这里一定要加上+的情况
                ++index;
        }            
        while(index < s.length() && '0'<=s[index] && s[index]<='9'){
            if(sign > 0 && result >= 0.1 * (INT_MAX - int(s[index] - '0')))   //移项，防止溢出
                return INT_MAX;
            if(sign < 0 && -result <= 0.1 * (INT_MIN + int(s[index] - '0')))
                return INT_MIN;
            result = result * 10 + int(s[index] - '0');
            ++index;
        }
        return sign * result;
    }
};
