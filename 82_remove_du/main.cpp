#include <iostream>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode start(0);
        start.next = head;
        ListNode* cur = &start;
        while(cur->next != nullptr && cur->next->next != nullptr) {
//            ListNode *p = cur->next;
            ListNode *q = cur->next->next;
            //q = cur->next->next;
            if(cur->next->val == q->val) {
                while( q != nullptr && cur->next->val == q->val) {
//                    ListNode * to_delete = q;
                    q = q->next;
//                    delete to_delete;
                }
                cur->next = q;
//                delete p;
            }else{
                cur = cur->next;
            }
        }

        return start.next;


    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}