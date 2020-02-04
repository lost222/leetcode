#include <iostream>
using namespace std;



//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    void swapNode(ListNode* pre_swap){
        if(pre_swap->next == nullptr || pre_swap->next->next == nullptr) {return;}
//        ListNode* q = pre_swap->next;
        ListNode* r = pre_swap->next->next;
        pre_swap->next->next = r->next;
        r->next = pre_swap->next;
        pre_swap->next = r;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode p0(0);
        p0.next = head;
        ListNode* start = &p0;
        while (start != nullptr && start->next != nullptr) {
            swapNode(start);
            start = start->next->next;
        }
        return p0.next;
    }
};

void outlist(ListNode *head) {
    while (head != nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main() {
    ListNode a[4] = {1,2,3,4};
    for(int i=0; i<3;i++) {
        a[i].next = &(a[i+1]);
    }


    std::cout << "Hello, World!" << std::endl;

    outlist(a);

    Solution su;
    ListNode* new_head  = su.swapPairs(a);
    outlist(new_head);

    return 0;
}