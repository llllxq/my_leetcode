class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int num_int = 0;
        while(i < s.length()){
            if(s[i] == 'I'){
                if(i+1 < s.length() && s[i+1] == 'V'){
                    num_int += 4;
                    i += 2;
                }
                else if(i+1 < s.length() && s[i+1] == 'X'){
                    num_int += 9;
                    i += 2;
                }
                else{
                    num_int += 1;
                    ++i;
                }
            }
            else if(s[i] == 'X'){
                if(i+1 < s.length() && s[i+1] == 'L'){
                    num_int += 40;
                    i += 2;
                }
                else if(i+1 < s.length() && s[i+1] == 'C'){
                    num_int += 90;
                    i += 2;
                }
                else{
                    num_int += 10;
                    ++i;
                }
            }
            else if(s[i] == 'C'){
                if(i+1 < s.length() && s[i+1] == 'D'){
                    num_int += 400;
                    i += 2;
                }
                else if(i+1 < s.length() && s[i+1] == 'M'){
                    num_int += 900;
                    i += 2;
                }
                else{
                    num_int += 100;
                    ++i;
                }
            }
            else if(s[i] == 'V'){
                num_int += 5;
                ++i;
            }
            else if(s[i] == 'L'){
                num_int += 50;
                ++i;
            }
            else if(s[i] == 'D'){
                num_int += 500;
                ++i;
            }
            else if(s[i] == 'M'){
                num_int += 1000;
                ++i;
            }
        }
        return num_int;
    }
};
