class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = "";
        while(true){
            if(strs[0].size() > commonPrefix.size()){
                for(int i=1;i<strs.size();++i){   //直接从索引1开始，每次跟第0个比较
                    if(strs[i].size() > commonPrefix.size() &&
                        strs[0][commonPrefix.size()] == strs[i][commonPrefix.size()]) {} //不用变量省内存
                    else
                        return commonPrefix;
                }
                commonPrefix.push_back(strs[0][commonPrefix.size()]);
            }
            else
                return commonPrefix;
        }
    }
};
