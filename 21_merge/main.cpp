#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int not_null_list = 0;
        for(auto i : lists) {
            if(i != nullptr) {not_null_list++;}
        }
        int null_count = 0;
        ListNode head(0);
        ListNode * cur = &head;

        while (not_null_list != null_count) {
            // find min node, who
            int the_min = INT32_MAX;
            int who = 0;
            for(int i=0; i<lists.size(); i++) {
                auto l = lists[i];
                if(l == nullptr) { continue;}
                if(l->val < the_min) {
                    the_min = l->val;
                    who = i;
                    //l = l->next;
                }
            }

            cur->next = lists[who];
            lists[who] = lists[who]->next;
            if(lists[who] == nullptr){null_count++;}

            // move cur
            cur = cur->next;
        }

        return head.next;
    }
};


void out_chain(ListNode *start) {
    while (start != nullptr) {
        cout<<" "<<start->val;
        start = start->next;
    }
    cout<<endl;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode list1(1),p1(4),p2(5);
    ListNode list2(1),q1(3),q2(4);
    ListNode list3(2),r1(6);
    list1.next = &p1;
    p1.next = &p2;
    list2.next = &q1;
    q1.next = &q2;
    list3.next = &r1;

//    out_chain(&list1);
//    out_chain(&list2);
//    out_chain(&list3);


    Solution su;
    vector<ListNode*> a{&list1, &list2, &list3};
    for(auto i:a) {
        out_chain(i);
    }

    ListNode* h =   su.mergeKLists(a);
    out_chain(h);





    return 0;
}