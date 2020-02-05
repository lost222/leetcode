#include <iostream>
#include <vector>
#include <map>
//
// Created by 杨起 on 2018/9/13.
// 核心是一个数组，作为一个三进制数//依据选出数字不同有的位子可能是4进制维护，每次取出序列后该数组加一
//倒着遍历数组就能简单的实现进位维护， 正向遍历不能处理连续进位的情况 （022 + 1 = 100）



class leetcode_17{
public:
    std::map<int, std::string> table;
    std::vector<std::string> ans;
    std::vector<std::string> grab_from;
    std::vector<int> top;
    std::vector<int> count;
    std::vector<int> end_c;
    leetcode_17(){
        table[2]="abc";
        table[3]="def";
        table[4]="ghi";
        table[5]="jkl";
        table[6]="mno";
        table[7]="pqrs";
        table[8]="tuv";
        table[9]="wxyz";
    };
    std::string grab(const std::vector<std::string> &from_array, const std::vector<int> &count){
            std::string result;
            for(auto i=0; i<count.size();i++){
                result += from_array[i][count[i]];
            }
            return result;
    }

    void grab_list(){
        ans.push_back(grab(grab_from, count));
        if(count == end_c){ return;}
        count[count.size()-1]++;

        //进位检测
        for(decltype(count.size()) i=count.size()-1; i>0; i--){
            if(count[i] == top[i]){
                count[i]=0;
                count[i-1]++;
            }
        }

        grab_list();

    }

    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.empty()){return ans;}
        for(auto c : digits){
            int di = int(c) - 48;
            grab_from.push_back(table[di]);
        }
        for(const auto &str: grab_from){
            top.push_back(int(str.length()));
            end_c.push_back(int(str.length()) - 1);
            count.push_back(0);
        }
        grab_list();
        return ans;
    }
};
