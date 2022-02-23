class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(true)
        {
            if(x>0 && result > 0.1 * (INT_MAX - x%10))  //这里移项一下，就不会溢出了
                return 0;
            if(x<0 && result < 0.1 * (INT_MIN - x%10))
                return 0;
            result = result*10 + x%10;
            x /= 10;
            if(x == 0)
                break; 
        }
        return result;
    }
};
