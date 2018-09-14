//把anagrams-- 由同样字母组成的不同单词 放到同一个vector中
//核心是构造一个map， 以排序过的字符串做key

class Solution {
public:
    map<string, vector<string>> M;
    void fufill_M(vector<string>& strs){
        for(auto &str: strs){
            string str_back = str;
            sort(str_back.begin(), str_back.end());
            M[str_back].push_back(str);
        }
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        fufill_M(strs);
        vector<vector<string>> result;
        for(auto i=M.begin(); i!=M.end(); i++){
            result.push_back(i->second);
        }
        return result;
    }
        
};


