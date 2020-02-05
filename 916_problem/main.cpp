#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:

    vector<vector<int> > s2v(vector<string>& A) {
        vector<vector<int> > res;
        for(const auto &s : A) {
            vector<int> m(26);
            for(const auto &i : s) {
                m[i - 'a'] += 1;
            }
            res.push_back(m);
        }

        return res;
    }

    bool is_sub(vector<int> arr, vector<int> brr) {
        for(int i=0; i<26; i++) {
            if(arr[i] < brr[i]) return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<vector<int> > A_arr = s2v(A);
        vector<vector<int> > B_arr = s2v(B);


        //把B里的需求全部合并
        vector<int> all_need(26, 0);
        for(const vector<int>& word : B_arr) {
            for(int i=0; i<26; i++) {
                all_need[i] = word[i] > all_need[i] ? word[i] : all_need[i];
            }
        }



        vector<string> res;
        for(int i=0; i<A_arr.size(); i++) {
            if(is_sub(A_arr[i], all_need)) {
                res.push_back(A[i]);
            }
        }

        return res;

    }
};


int main() {
    cout<<"hello world"<<endl;
    vector<string> A = {"amazon","apple","facebook","google","leetcode"};
    vector<string> B = {"e", "o"};

    Solution solution;
    vector<string> res = solution.wordSubsets(A, B);

    for(const auto& s:res) {
        cout<<s<<endl;
    }


    return 0;
}