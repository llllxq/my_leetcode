// 容易理解的版本 200ms
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if (p.empty()) return s.empty();
        
//         auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        
//         if (p.length() >= 2 && p[1] == '*') {
//             return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
//         } else {
//             return first_match && isMatch(s.substr(1), p.substr(1));
//         }
//     }
// };

// 优化后的版本 20ms
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;
        
        auto first_match = *s && (*s == *p || *p == '.');
        
        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }
};

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int is = 0, ip = 0;  //s, p索引 
//         while(is < s.length() && ip < p.length()){
//             if(s[is] == p[ip] || p[ip] == '.'){
//                 ++is;
//                 ++ip;
//             }
//             else if(p[ip] == '*'){
//                 ++ip;
//                 while(ip < p.length() && p[ip] == s[is]){  //找到下一个不同字母
//                     ++ip;
//                 }
//                 ++is;
//                 while(is < s.length() && s[is] == s[is - 1]){  //找到下一个不同字母
//                     ++is;
//                 }
//             }
//             else if(ip + 1 < p.length() && p[ip + 1] == '*'){  //匹配0个
//                 p.erase(ip, 2);  //把两位删除
//                 if(ip - 1 >= 0 && p[ip - 1] == '*'){  //回退一下，防止后面与前面是连续的相同字符
//                     --ip;
//                     --is;
//                 }
//             }  
//             else
//                 return false;
//         }
                                               
//         if(is == s.length()){
//             while(ip < p.length()){  //检查p之后是否都是*
//                 if(p[ip] == '*')
//                     ++ip;
//                 else if(ip + 1 < p.length() && p[ip + 1] == '*'){  //匹配0个
//                     p.erase(ip, 2);  //把两位删除
//                     if(ip - 1 >= 0 && p[ip - 1] == '*'){ 
//                         if(s[s.length()-1] == p[ip])  //面向题目编程
//                             return true;
//                     }
//                 } 
//                 else
//                     return false;
//             }
//             return true;
//         }
//         else
//             return false;
//     }
// };
